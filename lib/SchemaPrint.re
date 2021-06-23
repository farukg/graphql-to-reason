open Ppxlib;
open Migrate_parsetree.Ast_404;

open Ast_builder.Default.Located;
open Parsetree;
open Ast_helper;
open Ast_mapper;
open Schema;
let loc = default_loc^;
type state = {
  mutable enums: list(type_declaration),
  mutable unions: list(type_declaration),
  mutable unions_helpers: list(structure_item),
  mutable scalars: list(signature_item),
  mutable interfaces: list(type_declaration),
  mutable inputs: list(type_declaration),
  mutable fields: list(type_declaration),
  mutable directives: list(label_declaration),
  mutable queries: list(label_declaration),
  mutable mutations: list(label_declaration),
  mutable resolvers: list(structure_item),
  mutable subscriptions: list(label_declaration),
  mutable used_resolvers: list(string),
};

let uncap = String.uncapitalize_ascii;

let uncap_key =
  fun
  | "ID" => "id"
  | "JSON" => "json"
  | "CSS" => "css"
  | s => uncap(s);

let closed_js_t = fields => {
  Typ.constr(
    {txt: Longident.parse("Js.t"), loc: Location.none},
    [Typ.object_(fields, Closed)],
  );
};

let prefixes: Hashtbl.t(string, int) = Hashtbl.create(10);
let fieldNames: Hashtbl.t(string, int) = Hashtbl.create(10);

let fieldName = (key: string) =>
  switch (Hashtbl.find(fieldNames, key)) {
  | counter =>
    Hashtbl.add(fieldNames, key, counter + 1);
    key;
  | exception Not_found =>
    Hashtbl.add(fieldNames, key, 1);
    key;
  };
let resetFieldNames = () => Hashtbl.clear(fieldNames);
let filterList = (l, getKey) => {
  resetFieldNames();
  List.filter(
    a => {
      let x = getKey(a);
      switch (Hashtbl.find(fieldNames, x)) {
      | counter =>
        Hashtbl.add(fieldNames, x, counter + 1);
        false;
      | exception Not_found =>
        Hashtbl.add(fieldNames, x, 1);
        true;
      };
    },
    l,
  );
};
let filterList = (l, getKey) => {
  resetFieldNames();
  List.filter(a => true, l);
};
let prefix = (key: string) =>
  switch (Hashtbl.find(prefixes, key)) {
  | counter =>
    Hashtbl.add(prefixes, key, counter + 1);
    key;
  | exception Not_found =>
    Hashtbl.add(prefixes, key, 1);
    key;
  };

let resetPrefixes = () => Hashtbl.clear(prefixes);

let escape_id = key => {
  let originalKey = uncap_key(key);
  switch (originalKey) {
  | "and"
  | "see"
  | "let"
  | "type"
  | "class"
  | "as"
  | "assert"
  | "begin"
  | "constraint"
  | "do"
  | "while"
  | "for"
  | "done"
  | "downto"
  | "else"
  | "if"
  | "end"
  | "exception"
  | "external"
  | "false"
  | "fun"
  | "function"
  | "functor"
  | "in"
  | "include"
  | "inherit"
  | "initializer"
  | "lazy"
  | "match"
  | "method"
  | "module"
  | "mutable"
  | "new"
  | "object"
  | "of"
  | "open"
  | "or"
  | "private"
  | "rec"
  | "sig"
  | "struct"
  | "then"
  | "to"
  | "true"
  | "try"
  | "val"
  | "virtual"
  | "when"
  | "with" => (
      originalKey ++ "_",
      [
        (
          {Location.txt: "bs.as", loc: Location.none},
          PStr([%str [%e Exp.constant(Const.string(originalKey))]]),
        ),
      ],
    )
  | originalKey when originalKey != key => (originalKey, [])
  | originalKey => (originalKey, [])
  };
};
let gql_type = key =>
  switch (String.lowercase_ascii(key)) {
  | "id" => [%type: string]
  | "int" => [%type: int]
  | "boolean" => [%type: bool]
  | "float" => [%type: float]
  | "string" => [%type: string]
  | _ =>
    Typ.constr(
      {txt: Longident.Lident(uncap_key(key)), loc: Location.none},
      [],
    )
  };

let abstractRecord = (name, labels) =>
  Type.mk(
    ~kind=Ptype_record(labels),
    ~attrs=[],
    {Location.txt: name, loc: Location.none},
  );

let enum = (name, strings) =>
  Type.mk(
    ~kind=Ptype_abstract,
    ~attrs=[],
    ~manifest=
      Typ.variant(
        List.map(name => Rtag(name, [], true, []), strings),
        Closed,
        None,
      ),
    {Location.txt: name, loc: Location.none},
  );

let print = schema => {
  let state = {
    enums: [],
    unions: [],
    unions_helpers: [],
    scalars: [],
    interfaces: [],
    inputs: [],
    fields: [],
    directives: [],
    queries: [],
    mutations: [],
    resolvers: [],
    used_resolvers: [],
    subscriptions: [],
  };

  let uncap_key_resolver = s =>
    switch (Schema.lookup_type(schema, s)) {
    | Some(Enum(_)) => uncap_key(s)
    | None => uncap(s)
    | Some(Scalar(_))
    | Some(Object(_))
    | Some(Interface(_))
    | Some(Union(_))
    | Some(InputObject(_)) => uncap_key(s)
    };

  let rec print_type_ref_nonNullable = (~uncap_key=uncap_key, tm) =>
    switch (tm) {
    | Named(name) => uncap_key(name) |> gql_type
    | NonNull(tr) => print_type_ref_nonNullable(~uncap_key, tr)
    | List(tr) => [%type: array([%t print_type_ref(~uncap_key, tr)])]
    }
  and print_type_ref = (~uncap_key=uncap_key, tm) =>
    switch (tm) {
    | Named(name) => [%type: option([%t name |> uncap_key |> gql_type])]
    | NonNull(tr) => print_type_ref_nonNullable(~uncap_key, tr)
    | List(tr) => [%type:
        option(array([%t print_type_ref(~uncap_key, tr)]))
      ]
    };

  //  let rec print_field_type_name = (~uncap_key=uncap_key, tm) =>
  //    switch (tm) {
  //    | Named(name) => name |> uncap_key |> gql_type
  //    | NonNull(tr)
  //    | List(tr) => print_field_type_name(~uncap_key, tr)
  //    };

  let rec print_fields = (name, fields) =>
    Type.mk(
      ~kind=Ptype_record(print_record_fields(fields)),
      {Location.txt: name |> uncap_key, loc: Location.none},
    )
  and print_record_fields = fields =>
    List.map(print_record_field, filterList(fields, a => a.fm_name))
  and print_record_field = ({fm_name, fm_field_type, _}) => {
    let (key, extraAttrs) = escape_id(fm_name);
    let key = prefix(key);

    Type.field(
      {Location.txt: key, loc: Location.none},
      print_type_ref(fm_field_type),
    );
  }

  and print_root_resolver = fields =>
    List.map(
      ({fm_name, fm_arguments, fm_field_type, _}) => {
        let (key, extraAttrs) = escape_id(fm_name);
        let key = prefix(key);
        Type.field(
          ~attrs=extraAttrs,
          {Location.txt: key, loc: Location.none},
          Typ.constr(
            {txt: Longident.parse("rootResolver"), loc: Location.none},
            [
              switch (fm_arguments) {
              | [] => [%type: unit]
              | _ => closed_js_t(List.map(print_arg, fm_arguments))
              },
              Typ.constr(
                {txt: Longident.Lident("Config.ctx"), loc: Location.none},
                [],
              ),
              Typ.constr(
                {txt: Longident.Lident("Config.info"), loc: Location.none},
                [],
              ),
              print_type_ref(fm_field_type),
            ],
          ),
        );
      },
      fields,
    )
  and print_resolver = (parent, fields) =>
    List.map(
      ({fm_name, fm_arguments, fm_field_type, _}) => {
        let (key, extraAttrs) = escape_id(fm_name);
        let key = prefix(key);

        Type.field(
          ~attrs=extraAttrs,
          {Location.txt: key, loc: Location.none},
          Typ.constr(
            {
              txt: Longident.parse("Config.fieldResolver"),
              loc: Location.none,
            },
            [
              Typ.constr(
                {txt: Longident.Lident(parent), loc: Location.none},
                [],
              ),
              switch (fm_arguments) {
              | [] => [%type: unit]
              | _ => closed_js_t(List.map(print_arg, fm_arguments))
              },
              Typ.constr(
                {txt: Longident.Lident("Config.ctx"), loc: Location.none},
                [],
              ),
              Typ.constr(
                {txt: Longident.Lident("Config.info"), loc: Location.none},
                [],
              ),
              // print_field_type_name(fm_field_type),
              print_type_ref(fm_field_type),
            ],
          ),
        );
      },
      fields,
    )
  and print_directive_resolver = ({dm_name, dm_arguments, _}) => {
    let (key, extraAttrs) = escape_id(dm_name);
    let key = prefix(key);

    [
      Type.field(
        ~attrs=extraAttrs,
        {Location.txt: key, loc: Location.none},
        Typ.constr(
          {txt: Longident.parse("directiveResolver"), loc: Location.none},
          [
            switch (dm_arguments) {
            | [] => [%type: unit]
            | _ => closed_js_t(List.map(print_arg, dm_arguments))
            },
          ],
        ),
      ),
    ];
  }
  and print_scalar = ({sm_name, _}) =>
    switch (sm_name) {
    | "String"
    | "Float"
    | "Boolean"
    | "Int" => None
    | name =>
      Some(
        Sig.type_(
          Recursive,
          [Type.mk({Location.txt: uncap_key(name), loc: Location.none})],
        ),
      )
    }
  and print_enum = ({em_name, em_values, _}) =>
    switch (em_name) {
    | isPrivate when String.sub(isPrivate, 0, 2) == "__" => None
    | em_name =>
      let name = uncap_key(em_name);
      Some(
        enum(
          name,
          List.map(
            ({evm_name, _}) => evm_name,
            filterList(em_values, a => a.evm_name),
          ),
        ),
      );
    }
  and print_union = ({um_name, _}) =>
    Type.mk({Location.txt: uncap_key(um_name), loc: Location.none})
  and print_union_runtime = ({um_name, um_of_types, _}) => {
    let unionName = uncap_key(um_name);
    let suffix = "To" ++ (unionName |> String.capitalize_ascii);

    List.map(
      t => {
        let unionType = uncap_key(t);
        let arrowType =
          Typ.arrow(
            Nolabel,
            Typ.constr(
              {txt: Longident.Lident(unionType), loc: Location.none},
              [],
            ),
            Typ.constr(
              {txt: Longident.Lident(unionName), loc: Location.none},
              [],
            ),
          );
        Str.primitive(
          Val.mk(
            ~prim=["%identity"],
            {txt: unionType ++ suffix, loc: Location.none},
            arrowType,
          ),
        );
      },
      um_of_types,
    );
  }
  and print_field_jsT = ({fm_name, fm_field_type, _}) => (
    fm_name,
    [],
    print_type_ref(fm_field_type),
  )
  and print_interface = ({im_name, im_fields, _}) =>
    Type.mk(
      ~manifest=closed_js_t(List.map(print_field_jsT, im_fields)),
      {Location.txt: uncap_key(im_name), loc: Location.none},
    )
  and print_input = ({iom_name, iom_input_fields, _}) =>
    print_args(iom_name, iom_input_fields)

  and print_arg = ({am_name, am_arg_type, _}) => (
    am_name,
    [],
    print_type_ref(~uncap_key=uncap_key_resolver, am_arg_type),
  )
  and print_args = (name, args) => {
    let (key, extraAttrs) = escape_id(name);
    let x =
      List.map(
        ({am_name, am_arg_type, _}) => {
          let (key, extraAttrs) = escape_id(am_name);
          Type.field(
            {Location.txt: key, loc: Location.none},
            print_type_ref(am_arg_type),
          );
        },
        args,
      );
    Type.mk(
      ~kind=Ptype_record(x),
      {Location.txt: key |> uncap_key, loc: Location.none},
    );
  };

  Hashtbl.iter(
    (_key, type_meta) =>
      switch (type_meta) {
      | Object({om_name, om_fields, _}) =>
        switch (String.lowercase_ascii(om_name)) {
        | isPrivate when String.sub(isPrivate, 0, 2) == "__" => ()
        | name =>
          state.fields = [
            print_fields(om_name, filterList(om_fields, a => a.fm_name)),
            ...state.fields,
          ];
          state.used_resolvers =
            List.append(state.used_resolvers, [om_name]);
          resetPrefixes();

          switch (name) {
          | "mutation" =>
            state.mutations =
              List.append(state.mutations, print_root_resolver(om_fields))
          | "query" =>
            state.queries =
              List.append(state.queries, print_root_resolver(om_fields))
          | "subscription" =>
            state.subscriptions =
              List.append(
                state.subscriptions,
                print_root_resolver(om_fields),
              )
          | _ =>
            let resolverType =
              Type.mk(
                ~kind=
                  Ptype_record(
                    print_resolver(om_name |> uncap_key, om_fields),
                  ),
                ~attrs=[],
                {Location.txt: "t", loc: Location.none},
              );
            state.resolvers =
              List.append(
                state.resolvers,
                [
                  {
                    pstr_desc:
                      Pstr_module({
                        pmb_name: {
                          txt: om_name |> String.capitalize_ascii,
                          loc: Location.none,
                        },
                        pmb_expr:
                          Mod.mk(
                            Pmod_structure([
                              {
                                pstr_desc:
                                  Pstr_type(Recursive, [resolverType]),
                                pstr_loc: Location.none,
                              },
                            ]),
                          ),
                        pmb_attributes: [],
                        pmb_loc: Location.none,
                      }),
                    pstr_loc: Location.none,
                  },
                ],
              );
          };
        }

      | Scalar(sm) =>
        switch (print_scalar(sm)) {
        | Some(td) => state.scalars = [td, ...state.scalars]
        | None => ()
        }
      | Enum(em) =>
        switch (print_enum(em)) {
        | Some(td) => state.enums = [td, ...state.enums]
        | None => ()
        }
      | Interface(im) =>
        state.interfaces = [print_interface(im), ...state.interfaces]
      | Union(um) =>
        state.unions_helpers =
          List.append(print_union_runtime(um), state.unions_helpers);
        state.unions = [print_union(um), ...state.unions];
      | InputObject(iom) =>
        state.inputs = [print_input(iom), ...state.inputs]
      },
    schema.type_map,
  );

  Hashtbl.iter(
    (_key, dm) =>
      state.directives =
        List.append(state.directives, print_directive_resolver(dm)),
    schema.directive_map,
  );

  resetPrefixes();

  let enums =
    switch (state.enums) {
    | _ => Str.type_(Recursive, state.enums)
    };

  let inputs =
    switch (state.inputs) {
    | _ => Str.type_(Recursive, state.inputs)
    };

  let queries =
    switch (state.queries) {
    | _ => Str.type_(Recursive, [abstractRecord("t", state.queries)])
    };

  let mutations =
    switch (state.mutations) {
    | [] => [%str
        module Mutation = {}
      ]
    | _ => [%str
        module Mutation = {
          %i
          Str.type_(Recursive, [abstractRecord("t", state.mutations)]);
        }
      ]
    };
  let subscriptions =
    switch (state.subscriptions) {
    | [] => [%str
        module Subscription = {}
      ]
    | _ => [%str
        module Subscription = {
          %i
          Str.type_(Recursive, [abstractRecord("t", state.subscriptions)]);
        }
      ]
    };
  let directives =
    switch (state.directives) {
    | [] => [%str
        module Directives = {}
      ]
    | _ => [%str
        module Directives = {
          %i
          Str.type_(Recursive, [abstractRecord("t", state.directives)]);
        }
      ]
    };

  let resolvers =
    switch (state.resolvers) {
    | _ => state.resolvers
    };

  let used_resolvers =
    switch (state.used_resolvers) {
    | _ =>
      resetPrefixes();
      let labels =
        List.map(
          name => {
            let (key, extraAttrs) = escape_id(name);
            let key = prefix(key);

            let attrs = extraAttrs;
            Type.field(
              ~attrs,
              {Location.txt: key, loc: Location.none},
              Typ.constr(
                {
                  txt:
                    Ldot(
                      Longident.parse(name |> String.capitalize_ascii),
                      "t",
                    ),
                  loc: Location.none,
                },
                [],
              ),
            );
          },
          state.used_resolvers,
        );
      resetPrefixes();

      Str.type_(Recursive, [abstractRecord("t", labels)]);
    };

  let fields =
    switch (state.fields) {
    | _ =>
      Str.type_(
        Recursive,
        List.flatten([state.unions, state.interfaces, state.fields]),
      )
    };

  let code0 = [%str
    module type SchemaConfig = {
      module Scalars: [%m
        [%expr
          [%e
            {
              pmty_desc: Pmty_signature(state.scalars),
              pmty_loc: loc,
              pmty_attributes: [],
            }
          ]
        ]
      ];
      type ctx;
      type info;
      type rootValue;
      type resolver('parent, 'payload, 'ctx, 'fieldType, 'result);
      type fieldResolver('parent, 'vars, 'ctx, 'info, 'result);
      type directiveResolver('payload);
    }
  ];
  let code = [%str
    include Config.Scalars;
    type ctx = Config.ctx;
    type rootResolver('vars, 'ctx, 'info, 'result) =
      Config.fieldResolver(unit, 'vars, Config.ctx, 'info, 'result);
    type directiveResolver('payload) = Config.directiveResolver('payload)
  ];
  let code = List.append(code, [enums]);
  let code = List.append(code, [inputs]);

  let code = List.append(code, [fields, ...state.unions_helpers]);
  let code =
    List.append(
      code,
      [%str
        module Query = {
          %i
          queries;
        }
      ],
    );
  let code =
    List.length(mutations) > 0 ? List.append(code, mutations) : code;
  let code =
    List.length(subscriptions) > 0 ? List.append(code, subscriptions) : code;
  let code =
    List.length(directives) > 0 ? List.append(code, directives) : code;

  let code = List.append(code, resolvers);
  let code = List.append(code, [used_resolvers]);

  let code2 = [%stri
    module MakeSchema = (Config: SchemaConfig) => [%m
      [%expr
        [%e
          {
            pmod_desc: Pmod_structure(code),
            pmod_loc: Location.none,
            pmod_attributes: [],
          }
        ]
      ]
    ]
  ];
  let code = List.append(code0, [code2]);
  let comments = [];
  (code, comments);
};
