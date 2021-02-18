module type SchemaConfig = {
  module Scalars: {
    type id;
    type customScalar;
  };
  type resolver('parent, 'payload, 'fieldType, 'result);
  type directiveResolver('payload);
};
module MakeSchema = (Config: SchemaConfig) => {
  include Config.Scalars;
  type rootResolver('payload, 'fieldType, 'result) =
    Config.resolver(unit, 'payload, 'fieldType, 'result);
  type directiveResolver('payload) = Config.directiveResolver('payload);
  type sampleField = [ | `FIRST | `SECOND | `THIRD];
  type nonrecursiveInput = {
    field: option(string),
    enum: option(sampleField),
  }
  and listsInput = {
    nullableOfNullable: option(array(option(string))),
    nullableOfNonNullable: option(array(string)),
    nonNullableOfNullable: array(option(string)),
    nonNullableOfNonNullable: array(string),
  }
  and variousScalarsInput = {
    nullableString: option(string),
    string,
    nullableInt: option(int),
    int,
    nullableFloat: option(float),
    float,
    nullableBoolean: option(bool),
    boolean: bool,
    nullableID: option(string),
    id: string,
  }
  and recursiveInput = {
    otherField: option(string),
    inner: option(recursiveInput),
    enum: option(sampleField),
  };
  type dogOrHuman
  and nestedObject = {
    inner: option(nestedObject),
    field: string,
  }
  and sampleError = {
    field: sampleField,
    message: string,
  }
  and variousScalars = {
    nullableString: option(string),
    string,
    nullableInt: option(int),
    int,
    nullableFloat: option(float),
    float,
    nullableBoolean: option(bool),
    boolean: bool,
    nullableID: option(string),
    id: string,
  }
  and query = {
    stringField: string,
    variousScalars,
    lists,
    scalarsInput: string,
    listsInput: string,
    recursiveInput: string,
    nonrecursiveInput: string,
    enumInput: string,
    argNamedQuery: int,
    customScalarField: customScalarObject,
    dogOrHuman,
    nestedObject,
  }
  and mutationWithErrorResult = {
    value: option(sampleResult),
    errors: option(array(sampleError)),
  }
  and dog = {
    name: string,
    barkVolume: float,
  }
  and human = {name: string}
  and withArgField = {argField: option(nestedObject)}
  and subscription = {
    simpleSubscription: dogOrHuman,
    simpleNullableSubscription: option(dogOrHuman),
  }
  and lists = {
    nullableOfNullable: option(array(option(string))),
    nullableOfNonNullable: option(array(string)),
    nonNullableOfNullable: array(option(string)),
    nonNullableOfNonNullable: array(string),
  }
  and sampleResult = {stringField: string}
  and customScalarObject = {
    nullable: option(customScalar),
    nonNullable: customScalar,
  }
  and mutation = {mutationWithError: mutationWithErrorResult};
  external dogToDogOrHuman: dog => dogOrHuman = "%identity";
  external humanToDogOrHuman: human => dogOrHuman = "%identity";
  module Query = {
    type t = {
      stringField: rootResolver(unit, string, string),
      variousScalars: rootResolver(unit, variousScalars, variousScalars),
      lists: rootResolver(unit, lists, lists),
      scalarsInput:
        rootResolver({. "arg": variousScalarsInput}, string, string),
      listsInput: rootResolver({. "arg": listsInput}, string, string),
      recursiveInput:
        rootResolver({. "arg": recursiveInput}, string, string),
      nonrecursiveInput:
        rootResolver({. "arg": nonrecursiveInput}, string, string),
      enumInput: rootResolver({. "arg": sampleField}, string, string),
      argNamedQuery: rootResolver({. "query": int}, int, int),
      customScalarField:
        rootResolver(
          {
            .
            "argOptional": option(customScalar),
            "argRequired": customScalar,
          },
          customScalarObject,
          customScalarObject,
        ),
      dogOrHuman: rootResolver(unit, dogOrHuman, dogOrHuman),
      nestedObject: rootResolver(unit, nestedObject, nestedObject),
    };
  };
  module Mutation = {
    type t = {
      mutationWithError:
        rootResolver(unit, mutationWithErrorResult, mutationWithErrorResult),
    };
  };
  module Subscription = {
    type t = {
      simpleSubscription: rootResolver(unit, dogOrHuman, dogOrHuman),
      simpleNullableSubscription:
        rootResolver(unit, dogOrHuman, option(dogOrHuman)),
    };
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
  module CustomScalarObject = {
    type t = {
      nullable:
        Config.resolver(
          customScalarObject,
          unit,
          customScalar,
          option(customScalar),
        ),
      nonNullable:
        Config.resolver(customScalarObject, unit, customScalar, customScalar),
    };
  };
  module SampleResult = {
    type t = {
      stringField: Config.resolver(sampleResult, unit, string, string),
    };
  };
  module Lists = {
    type t = {
      nullableOfNullable:
        Config.resolver(
          lists,
          unit,
          string,
          option(array(option(string))),
        ),
      nullableOfNonNullable:
        Config.resolver(lists, unit, string, option(array(string))),
      nonNullableOfNullable:
        Config.resolver(lists, unit, string, array(option(string))),
      nonNullableOfNonNullable:
        Config.resolver(lists, unit, string, array(string)),
    };
  };
  module WithArgField = {
    type t = {
      argField:
        Config.resolver(
          withArgField,
          {
            .
            "arg1": option(string),
            "arg2": option(int),
          },
          nestedObject,
          option(nestedObject),
        ),
    };
  };
  module Human = {
    type t = {name: Config.resolver(human, unit, string, string)};
  };
  module Dog = {
    type t = {
      name: Config.resolver(dog, unit, string, string),
      barkVolume: Config.resolver(dog, unit, float, float),
    };
  };
  module MutationWithErrorResult = {
    type t = {
      value:
        Config.resolver(
          mutationWithErrorResult,
          unit,
          sampleResult,
          option(sampleResult),
        ),
      errors:
        Config.resolver(
          mutationWithErrorResult,
          unit,
          sampleError,
          option(array(sampleError)),
        ),
    };
  };
  module VariousScalars = {
    type t = {
      nullableString:
        Config.resolver(variousScalars, unit, string, option(string)),
      string: Config.resolver(variousScalars, unit, string, string),
      nullableInt: Config.resolver(variousScalars, unit, int, option(int)),
      int: Config.resolver(variousScalars, unit, int, int),
      nullableFloat:
        Config.resolver(variousScalars, unit, float, option(float)),
      float: Config.resolver(variousScalars, unit, float, float),
      nullableBoolean:
        Config.resolver(variousScalars, unit, bool, option(bool)),
      boolean: Config.resolver(variousScalars, unit, bool, bool),
      nullableID:
        Config.resolver(variousScalars, unit, string, option(string)),
      id: Config.resolver(variousScalars, unit, string, string),
    };
  };
  module SampleError = {
    type t = {
      field: Config.resolver(sampleError, unit, sampleField, sampleField),
      message: Config.resolver(sampleError, unit, string, string),
    };
  };
  module NestedObject = {
    type t = {
      inner:
        Config.resolver(
          nestedObject,
          unit,
          nestedObject,
          option(nestedObject),
        ),
      field: Config.resolver(nestedObject, unit, string, string),
    };
  };
  type t = {
    mutation: Mutation.t,
    customScalarObject: CustomScalarObject.t,
    sampleResult: SampleResult.t,
    lists: Lists.t,
    subscription: Subscription.t,
    withArgField: WithArgField.t,
    human: Human.t,
    dog: Dog.t,
    mutationWithErrorResult: MutationWithErrorResult.t,
    query: Query.t,
    variousScalars: VariousScalars.t,
    sampleError: SampleError.t,
    nestedObject: NestedObject.t,
  };
};
