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
  type episode = [ | `NEWHOPE | `EMPIRE | `JEDI]
  and lengthUnit = [ | `METER | `FOOT];
  type colorInput = {
    red: int,
    green: int,
    blue: int,
  }
  and reviewInput = {
    stars: int,
    commentary: option(string),
    favorite_color: option(colorInput),
  };
  type searchResult
  and character = {
    .
    "id": string,
    "name": string,
    "friends": option(array(option(character))),
    "friendsConnection": friendsConnection,
    "appearsIn": array(option(episode)),
  }
  and droid = {
    id: string,
    name: string,
    friends: option(array(option(character))),
    friendsConnection,
    appearsIn: array(option(episode)),
    primaryFunction: option(string),
  }
  and subscription = {reviewAdded: option(review)}
  and friendsConnection = {
    totalCount: option(int),
    edges: option(array(option(friendsEdge))),
    friends: option(array(option(character))),
    pageInfo,
  }
  and query = {
    hero: option(character),
    reviews: option(array(option(review))),
    search: option(array(option(searchResult))),
    character: option(character),
    droid: option(droid),
    human: option(human),
    starship: option(starship),
  }
  and friendsEdge = {
    cursor: string,
    node: option(character),
  }
  and mutation = {createReview: option(review)}
  and human = {
    id: string,
    name: string,
    homePlanet: option(string),
    height: option(float),
    mass: option(float),
    friends: option(array(option(character))),
    friendsConnection,
    appearsIn: array(option(episode)),
    starships: option(array(option(starship))),
  }
  and pageInfo = {
    startCursor: option(string),
    endCursor: option(string),
    hasNextPage: bool,
  }
  and starship = {
    id: string,
    name: string,
    length: option(float),
    coordinates: option(array(array(float))),
  }
  and review = {
    episode: option(episode),
    stars: int,
    commentary: option(string),
  };
  external humanToSearchResult: human => searchResult = "%identity";
  external droidToSearchResult: droid => searchResult = "%identity";
  external starshipToSearchResult: starship => searchResult = "%identity";
  module Query = {
    type t = {
      hero:
        rootResolver(
          {. "episode": option(episode)},
          character,
          option(character),
        ),
      reviews:
        rootResolver(
          {. "episode": episode},
          review,
          option(array(option(review))),
        ),
      search:
        rootResolver(
          {. "text": option(string)},
          searchResult,
          option(array(option(searchResult))),
        ),
      character:
        rootResolver({. "id": string}, character, option(character)),
      droid: rootResolver({. "id": string}, droid, option(droid)),
      human: rootResolver({. "id": string}, human, option(human)),
      starship: rootResolver({. "id": string}, starship, option(starship)),
    };
  };
  module Mutation = {
    type t = {
      createReview:
        rootResolver(
          {
            .
            "episode": option(episode),
            "review": reviewInput,
          },
          review,
          option(review),
        ),
    };
  };
  module Subscription = {
    type t = {
      reviewAdded:
        rootResolver(
          {. "episode": option(episode)},
          review,
          option(review),
        ),
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
  module Review = {
    type t = {
      episode: Config.resolver(review, unit, episode, option(episode)),
      stars: Config.resolver(review, unit, int, int),
      commentary: Config.resolver(review, unit, string, option(string)),
    };
  };
  module Starship = {
    type t = {
      id: Config.resolver(starship, unit, string, string),
      name: Config.resolver(starship, unit, string, string),
      length:
        Config.resolver(
          starship,
          {. "unit": option(lengthUnit)},
          float,
          option(float),
        ),
      coordinates:
        Config.resolver(
          starship,
          unit,
          float,
          option(array(array(float))),
        ),
    };
  };
  module PageInfo = {
    type t = {
      startCursor: Config.resolver(pageInfo, unit, string, option(string)),
      endCursor: Config.resolver(pageInfo, unit, string, option(string)),
      hasNextPage: Config.resolver(pageInfo, unit, bool, bool),
    };
  };
  module Human = {
    type t = {
      id: Config.resolver(human, unit, string, string),
      name: Config.resolver(human, unit, string, string),
      homePlanet: Config.resolver(human, unit, string, option(string)),
      height:
        Config.resolver(
          human,
          {. "unit": option(lengthUnit)},
          float,
          option(float),
        ),
      mass: Config.resolver(human, unit, float, option(float)),
      friends:
        Config.resolver(
          human,
          unit,
          character,
          option(array(option(character))),
        ),
      friendsConnection:
        Config.resolver(
          human,
          {
            .
            "first": option(int),
            "after": option(string),
          },
          friendsConnection,
          friendsConnection,
        ),
      appearsIn:
        Config.resolver(human, unit, episode, array(option(episode))),
      starships:
        Config.resolver(
          human,
          unit,
          starship,
          option(array(option(starship))),
        ),
    };
  };
  module FriendsEdge = {
    type t = {
      cursor: Config.resolver(friendsEdge, unit, string, string),
      node: Config.resolver(friendsEdge, unit, character, option(character)),
    };
  };
  module FriendsConnection = {
    type t = {
      totalCount: Config.resolver(friendsConnection, unit, int, option(int)),
      edges:
        Config.resolver(
          friendsConnection,
          unit,
          friendsEdge,
          option(array(option(friendsEdge))),
        ),
      friends:
        Config.resolver(
          friendsConnection,
          unit,
          character,
          option(array(option(character))),
        ),
      pageInfo: Config.resolver(friendsConnection, unit, pageInfo, pageInfo),
    };
  };
  module Droid = {
    type t = {
      id: Config.resolver(droid, unit, string, string),
      name: Config.resolver(droid, unit, string, string),
      friends:
        Config.resolver(
          droid,
          unit,
          character,
          option(array(option(character))),
        ),
      friendsConnection:
        Config.resolver(
          droid,
          {
            .
            "first": option(int),
            "after": option(string),
          },
          friendsConnection,
          friendsConnection,
        ),
      appearsIn:
        Config.resolver(droid, unit, episode, array(option(episode))),
      primaryFunction: Config.resolver(droid, unit, string, option(string)),
    };
  };
  type t = {
    review: Review.t,
    starship: Starship.t,
    pageInfo: PageInfo.t,
    human: Human.t,
    mutation: Mutation.t,
    friendsEdge: FriendsEdge.t,
    query: Query.t,
    friendsConnection: FriendsConnection.t,
    subscription: Subscription.t,
    droid: Droid.t,
  };
};
