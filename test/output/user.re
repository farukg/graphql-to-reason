module type SchemaConfig = {
  module Scalars: {type id;};
  type resolver('parent, 'payload, 'fieldType, 'result);
  type directiveResolver('payload);
};
module MakeSchema = (Config: SchemaConfig) => {
  include Config.Scalars;
  type rootResolver('payload, 'fieldType, 'result) =
    Config.resolver(unit, 'payload, 'fieldType, 'result);
  type directiveResolver('payload) = Config.directiveResolver('payload);
  type userTypes = [ | `SuperUser | `Administrator | `Customer]
  and gender = [ | `Male | `Female | `NonBinary];
  type wrapper = {foo: option(string)}
  and genderInput = {
    check: bool,
    another: option(string),
    listOfStrings: array(option(string)),
    nullableListOfStrings: option(array(option(string))),
    wrapper,
    gender: option(gender),
  };
  type userLike = {. "name": string}
  and query = {user: option(user)}
  and user = {
    name: string,
    email: string,
    gender: option(gender),
    listNullable: option(array(option(string))),
    list: array(option(string)),
    getGender: gender,
    self: user,
  };
  module Query = {
    type t = {user: rootResolver(unit, user, option(user))};
  };
  module Mutation = {
    type t = {};
  };
  module Subscription = {
    type t = {};
  };
  module Directives = {
    type t = {
      [@bs.as "include"]
      include_: directiveResolver({. "if": bool}),
      skip: directiveResolver({. "if": bool}),
      deprecated: directiveResolver({. "reason": option(string)}),
      specifiedBy: directiveResolver({. "url": string}),
    };
  };
  module User = {
    type t = {
      name: Config.resolver(user, unit, string, string),
      email: Config.resolver(user, unit, string, string),
      gender: Config.resolver(user, unit, gender, option(gender)),
      listNullable:
        Config.resolver(user, unit, string, option(array(option(string)))),
      list: Config.resolver(user, unit, string, array(option(string))),
      getGender:
        Config.resolver(
          user,
          {. "check": option(genderInput)},
          gender,
          gender,
        ),
      self: Config.resolver(user, {. "check": bool}, user, user),
    };
  };
  type t = {
    user: User.t,
    query: Query.t,
  };
};
