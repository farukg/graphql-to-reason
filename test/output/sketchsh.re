module type SchemaConfig = {
  module Scalars: {
    type jsonb;
    type timestamptz;
  };
  type resolver('parent, 'payload, 'fieldType, 'result);
  type directiveResolver('payload);
};
module MakeSchema = (Config: SchemaConfig) => {
  include Config.Scalars;
  type rootResolver('payload, 'fieldType, 'result) =
    Config.resolver(unit, 'payload, 'fieldType, 'result);
  type directiveResolver('payload) = Config.directiveResolver('payload);
  type conflict_action = [ | `ignore | `update]
  and user_order_by = [
    | `avatar_asc
    | `avatar_asc_nulls_first
    | `avatar_desc
    | `avatar_desc_nulls_first
    | `created_at_asc
    | `created_at_asc_nulls_first
    | `created_at_desc
    | `created_at_desc_nulls_first
    | `email_asc
    | `email_asc_nulls_first
    | `email_desc
    | `email_desc_nulls_first
    | `id_asc
    | `id_asc_nulls_first
    | `id_desc
    | `id_desc_nulls_first
    | `name_asc
    | `name_asc_nulls_first
    | `name_desc
    | `name_desc_nulls_first
    | `updated_at_asc
    | `updated_at_asc_nulls_first
    | `updated_at_desc
    | `updated_at_desc_nulls_first
    | `username_asc
    | `username_asc_nulls_first
    | `username_desc
    | `username_desc_nulls_first
  ]
  and note_revision_order_by = [
    | `created_at_asc
    | `created_at_asc_nulls_first
    | `created_at_desc
    | `created_at_desc_nulls_first
    | `data_asc
    | `data_asc_nulls_first
    | `data_desc
    | `data_desc_nulls_first
    | `note_id_asc
    | `note_id_asc_nulls_first
    | `note_id_desc
    | `note_id_desc_nulls_first
    | `title_asc
    | `title_asc_nulls_first
    | `title_desc
    | `title_desc_nulls_first
  ]
  and user_identity_constraint = [ | `user_identity_pkey]
  and user_constraint = [ | `user_pkey]
  and user_identity_type_order_by = [
    | `user_identity_type_asc
    | `user_identity_type_asc_nulls_first
    | `user_identity_type_desc
    | `user_identity_type_desc_nulls_first
  ]
  and note_constraint = [ | `note_pkey]
  and note_revision_constraint = [ | `note_revision_pkey]
  and user_identity_order_by = [
    | `data_asc
    | `data_asc_nulls_first
    | `data_desc
    | `data_desc_nulls_first
    | `identity_id_asc
    | `identity_id_asc_nulls_first
    | `identity_id_desc
    | `identity_id_desc_nulls_first
    | `identity_type_asc
    | `identity_type_asc_nulls_first
    | `identity_type_desc
    | `identity_type_desc_nulls_first
    | `user_id_asc
    | `user_id_asc_nulls_first
    | `user_id_desc
    | `user_id_desc_nulls_first
  ]
  and note_order_by = [
    | `created_at_asc
    | `created_at_asc_nulls_first
    | `created_at_desc
    | `created_at_desc_nulls_first
    | `data_asc
    | `data_asc_nulls_first
    | `data_desc
    | `data_desc_nulls_first
    | `id_asc
    | `id_asc_nulls_first
    | `id_desc
    | `id_desc_nulls_first
    | `title_asc
    | `title_asc_nulls_first
    | `title_desc
    | `title_desc_nulls_first
    | `updated_at_asc
    | `updated_at_asc_nulls_first
    | `updated_at_desc
    | `updated_at_desc_nulls_first
    | `user_id_asc
    | `user_id_asc_nulls_first
    | `user_id_desc
    | `user_id_desc_nulls_first
  ]
  and user_identity_type_constraint = [ | `user_identity_type_pkey];
  type timestamptz_comparison_exp = {
    _eq: option(timestamptz),
    _gt: option(timestamptz),
    _gte: option(timestamptz),
    _in: option(array(option(timestamptz))),
    _is_null: option(bool),
    _lt: option(timestamptz),
    _lte: option(timestamptz),
    _neq: option(timestamptz),
    _nin: option(array(option(timestamptz))),
  }
  and note_prepend_input = {data: option(jsonb)}
  and user_identity_type_set_input = {user_identity_type: option(string)}
  and user_identity_type_bool_exp = {
    _and: option(array(option(user_identity_type_bool_exp))),
    _not: option(user_identity_type_bool_exp),
    _or: option(array(option(user_identity_type_bool_exp))),
    user_identity_type: option(varchar_comparison_exp),
  }
  and note_revision_delete_key_input = {data: option(string)}
  and note_revision_delete_at_path_input = {
    data: option(array(option(string))),
  }
  and note_revision_on_conflict = {
    action: conflict_action,
    constraint_: option(note_revision_constraint),
  }
  and note_delete_key_input = {data: option(string)}
  and user_identity_insert_input = {
    data: option(jsonb),
    identity_id: option(string),
    identity_type: option(string),
    user_id: option(string),
  }
  and user_identity_on_conflict = {
    action: conflict_action,
    constraint_: option(user_identity_constraint),
  }
  and note_revision_set_input = {
    created_at: option(timestamptz),
    data: option(jsonb),
    note_id: option(string),
    title: option(string),
  }
  and note_on_conflict = {
    action: conflict_action,
    constraint_: option(note_constraint),
  }
  and jsonb_comparison_exp = {
    _eq: option(jsonb),
    _gt: option(jsonb),
    _gte: option(jsonb),
    _in: option(array(option(jsonb))),
    _is_null: option(bool),
    _lt: option(jsonb),
    _lte: option(jsonb),
    _neq: option(jsonb),
    _nin: option(array(option(jsonb))),
  }
  and user_identity_delete_at_path_input = {
    data: option(array(option(string))),
  }
  and user_set_input = {
    avatar: option(string),
    created_at: option(timestamptz),
    email: option(string),
    id: option(string),
    name: option(string),
    updated_at: option(timestamptz),
    username: option(string),
  }
  and note_revision_prepend_input = {data: option(jsonb)}
  and note_append_input = {data: option(jsonb)}
  and user_identity_bool_exp = {
    _and: option(array(option(user_identity_bool_exp))),
    _not: option(user_identity_bool_exp),
    _or: option(array(option(user_identity_bool_exp))),
    data: option(jsonb_comparison_exp),
    identity_id: option(varchar_comparison_exp),
    identity_type: option(varchar_comparison_exp),
    user: option(user_bool_exp),
    user_id: option(varchar_comparison_exp),
  }
  and user_insert_input = {
    avatar: option(string),
    created_at: option(timestamptz),
    email: option(string),
    id: option(string),
    name: option(string),
    updated_at: option(timestamptz),
    username: option(string),
  }
  and note_insert_input = {
    created_at: option(timestamptz),
    data: option(jsonb),
    id: option(string),
    title: option(string),
    updated_at: option(timestamptz),
    user_id: option(string),
  }
  and user_identity_delete_elem_input = {data: option(int)}
  and note_set_input = {
    created_at: option(timestamptz),
    data: option(jsonb),
    id: option(string),
    title: option(string),
    updated_at: option(timestamptz),
    user_id: option(string),
  }
  and user_identity_set_input = {
    data: option(jsonb),
    identity_id: option(string),
    identity_type: option(string),
    user_id: option(string),
  }
  and user_identity_delete_key_input = {data: option(string)}
  and note_revision_delete_elem_input = {data: option(int)}
  and note_delete_at_path_input = {data: option(array(option(string)))}
  and note_bool_exp = {
    _and: option(array(option(note_bool_exp))),
    _not: option(note_bool_exp),
    _or: option(array(option(note_bool_exp))),
    created_at: option(timestamptz_comparison_exp),
    data: option(jsonb_comparison_exp),
    id: option(varchar_comparison_exp),
    notes: option(note_revision_bool_exp),
    title: option(text_comparison_exp),
    updated_at: option(timestamptz_comparison_exp),
    user: option(user_bool_exp),
    user_id: option(varchar_comparison_exp),
  }
  and user_identity_prepend_input = {data: option(jsonb)}
  and user_identity_type_insert_input = {user_identity_type: option(string)}
  and user_identity_append_input = {data: option(jsonb)}
  and note_delete_elem_input = {data: option(int)}
  and note_revision_insert_input = {
    created_at: option(timestamptz),
    data: option(jsonb),
    note_id: option(string),
    title: option(string),
  }
  and note_revision_bool_exp = {
    _and: option(array(option(note_revision_bool_exp))),
    _not: option(note_revision_bool_exp),
    _or: option(array(option(note_revision_bool_exp))),
    created_at: option(timestamptz_comparison_exp),
    data: option(jsonb_comparison_exp),
    note: option(note_bool_exp),
    note_id: option(varchar_comparison_exp),
    title: option(text_comparison_exp),
  }
  and note_revision_append_input = {data: option(jsonb)}
  and user_bool_exp = {
    _and: option(array(option(user_bool_exp))),
    _not: option(user_bool_exp),
    _or: option(array(option(user_bool_exp))),
    avatar: option(varchar_comparison_exp),
    created_at: option(timestamptz_comparison_exp),
    email: option(varchar_comparison_exp),
    id: option(varchar_comparison_exp),
    identities: option(user_identity_bool_exp),
    name: option(varchar_comparison_exp),
    notes: option(note_bool_exp),
    updated_at: option(timestamptz_comparison_exp),
    username: option(text_comparison_exp),
  }
  and user_identity_type_on_conflict = {
    action: conflict_action,
    constraint_: option(user_identity_type_constraint),
  }
  and user_on_conflict = {
    action: conflict_action,
    constraint_: option(user_constraint),
  }
  and text_comparison_exp = {
    _eq: option(string),
    _gt: option(string),
    _gte: option(string),
    _ilike: option(string),
    _in: option(array(option(string))),
    _is_null: option(bool),
    _like: option(string),
    _lt: option(string),
    _lte: option(string),
    _neq: option(string),
    _nilike: option(string),
    _nin: option(array(option(string))),
    _nlike: option(string),
    _nsimilar: option(string),
    _similar: option(string),
  }
  and varchar_comparison_exp = {
    _eq: option(string),
    _gt: option(string),
    _gte: option(string),
    _ilike: option(string),
    _in: option(array(option(string))),
    _is_null: option(bool),
    _like: option(string),
    _lt: option(string),
    _lte: option(string),
    _neq: option(string),
    _nilike: option(string),
    _nin: option(array(option(string))),
    _nlike: option(string),
    _nsimilar: option(string),
    _similar: option(string),
  };
  type user_identity_type_mutation_response = {
    affected_rows: int,
    returning: array(user_identity_type_no_rels),
  }
  and note_no_rels = {
    created_at: option(timestamptz),
    data: option(jsonb),
    id: option(string),
    title: option(string),
    updated_at: option(timestamptz),
    user_id: option(string),
  }
  and user_identity_mutation_response = {
    affected_rows: int,
    returning: array(user_identity_no_rels),
  }
  and mutation_root = {
    delete_note: option(note_mutation_response),
    delete_note_revision: option(note_revision_mutation_response),
    delete_user: option(user_mutation_response),
    delete_user_identity: option(user_identity_mutation_response),
    delete_user_identity_type: option(user_identity_type_mutation_response),
    insert_note: option(note_mutation_response),
    insert_note_revision: option(note_revision_mutation_response),
    insert_user: option(user_mutation_response),
    insert_user_identity: option(user_identity_mutation_response),
    insert_user_identity_type: option(user_identity_type_mutation_response),
    update_note: option(note_mutation_response),
    update_note_revision: option(note_revision_mutation_response),
    update_user: option(user_mutation_response),
    update_user_identity: option(user_identity_mutation_response),
    update_user_identity_type: option(user_identity_type_mutation_response),
  }
  and note_mutation_response = {
    affected_rows: int,
    returning: array(note_no_rels),
  }
  and note_revision_mutation_response = {
    affected_rows: int,
    returning: array(note_revision_no_rels),
  }
  and user_mutation_response = {
    affected_rows: int,
    returning: array(user_no_rels),
  }
  and user_no_rels = {
    avatar: option(string),
    created_at: option(timestamptz),
    email: option(string),
    id: option(string),
    name: option(string),
    updated_at: option(timestamptz),
    username: option(string),
  }
  and user_identity = {
    data: option(jsonb),
    identity_id: option(string),
    identity_type: option(string),
    user: option(user),
    user_id: option(string),
  }
  and user_identity_type = {user_identity_type: option(string)}
  and query_root = {
    note: array(note),
    note_revision: array(note_revision),
    user: array(user),
    user_identity: array(user_identity),
    user_identity_type: array(user_identity_type),
  }
  and user_identity_type_no_rels = {user_identity_type: option(string)}
  and note_revision_no_rels = {
    created_at: option(timestamptz),
    data: option(jsonb),
    note_id: option(string),
    title: option(string),
  }
  and note = {
    created_at: option(timestamptz),
    data: option(jsonb),
    id: option(string),
    notes: array(note_revision),
    title: option(string),
    updated_at: option(timestamptz),
    user: option(user),
    user_id: option(string),
  }
  and user_identity_no_rels = {
    data: option(jsonb),
    identity_id: option(string),
    identity_type: option(string),
    user_id: option(string),
  }
  and subscription_root = {
    note: array(note),
    note_revision: array(note_revision),
    user: array(user),
    user_identity: array(user_identity),
    user_identity_type: array(user_identity_type),
  }
  and user = {
    avatar: option(string),
    created_at: option(timestamptz),
    email: option(string),
    id: option(string),
    identities: array(user_identity),
    name: option(string),
    notes: array(note),
    updated_at: option(timestamptz),
    username: option(string),
  }
  and note_revision = {
    created_at: option(timestamptz),
    data: option(jsonb),
    note: option(note),
    note_id: option(string),
    title: option(string),
  };
  module Query = {
    type t = {};
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
  module Note_revision = {
    type t = {
      created_at:
        Config.resolver(
          note_revision,
          unit,
          timestamptz,
          option(timestamptz),
        ),
      data: Config.resolver(note_revision, unit, jsonb, option(jsonb)),
      note: Config.resolver(note_revision, unit, note, option(note)),
      note_id: Config.resolver(note_revision, unit, string, option(string)),
      title: Config.resolver(note_revision, unit, string, option(string)),
    };
  };
  module User = {
    type t = {
      avatar: Config.resolver(user, unit, string, option(string)),
      created_at:
        Config.resolver(user, unit, timestamptz, option(timestamptz)),
      email: Config.resolver(user, unit, string, option(string)),
      id: Config.resolver(user, unit, string, option(string)),
      identities:
        Config.resolver(
          user,
          {
            .
            "limit": option(int),
            "offset": option(int),
            "order_by": option(array(user_identity_order_by)),
            "where": option(user_identity_bool_exp),
          },
          user_identity,
          array(user_identity),
        ),
      name: Config.resolver(user, unit, string, option(string)),
      notes:
        Config.resolver(
          user,
          {
            .
            "limit": option(int),
            "offset": option(int),
            "order_by": option(array(note_order_by)),
            "where": option(note_bool_exp),
          },
          note,
          array(note),
        ),
      updated_at:
        Config.resolver(user, unit, timestamptz, option(timestamptz)),
      username: Config.resolver(user, unit, string, option(string)),
    };
  };
  module Subscription_root = {
    type t = {
      note:
        Config.resolver(
          subscription_root,
          {
            .
            "limit": option(int),
            "offset": option(int),
            "order_by": option(array(note_order_by)),
            "where": option(note_bool_exp),
          },
          note,
          array(note),
        ),
      note_revision:
        Config.resolver(
          subscription_root,
          {
            .
            "limit": option(int),
            "offset": option(int),
            "order_by": option(array(note_revision_order_by)),
            "where": option(note_revision_bool_exp),
          },
          note_revision,
          array(note_revision),
        ),
      user:
        Config.resolver(
          subscription_root,
          {
            .
            "limit": option(int),
            "offset": option(int),
            "order_by": option(array(user_order_by)),
            "where": option(user_bool_exp),
          },
          user,
          array(user),
        ),
      user_identity:
        Config.resolver(
          subscription_root,
          {
            .
            "limit": option(int),
            "offset": option(int),
            "order_by": option(array(user_identity_order_by)),
            "where": option(user_identity_bool_exp),
          },
          user_identity,
          array(user_identity),
        ),
      user_identity_type:
        Config.resolver(
          subscription_root,
          {
            .
            "limit": option(int),
            "offset": option(int),
            "order_by": option(array(user_identity_type_order_by)),
            "where": option(user_identity_type_bool_exp),
          },
          user_identity_type,
          array(user_identity_type),
        ),
    };
  };
  module User_identity_no_rels = {
    type t = {
      data:
        Config.resolver(user_identity_no_rels, unit, jsonb, option(jsonb)),
      identity_id:
        Config.resolver(user_identity_no_rels, unit, string, option(string)),
      identity_type:
        Config.resolver(user_identity_no_rels, unit, string, option(string)),
      user_id:
        Config.resolver(user_identity_no_rels, unit, string, option(string)),
    };
  };
  module Note = {
    type t = {
      created_at:
        Config.resolver(note, unit, timestamptz, option(timestamptz)),
      data: Config.resolver(note, unit, jsonb, option(jsonb)),
      id: Config.resolver(note, unit, string, option(string)),
      notes:
        Config.resolver(
          note,
          {
            .
            "limit": option(int),
            "offset": option(int),
            "order_by": option(array(note_revision_order_by)),
            "where": option(note_revision_bool_exp),
          },
          note_revision,
          array(note_revision),
        ),
      title: Config.resolver(note, unit, string, option(string)),
      updated_at:
        Config.resolver(note, unit, timestamptz, option(timestamptz)),
      user: Config.resolver(note, unit, user, option(user)),
      user_id: Config.resolver(note, unit, string, option(string)),
    };
  };
  module Note_revision_no_rels = {
    type t = {
      created_at:
        Config.resolver(
          note_revision_no_rels,
          unit,
          timestamptz,
          option(timestamptz),
        ),
      data:
        Config.resolver(note_revision_no_rels, unit, jsonb, option(jsonb)),
      note_id:
        Config.resolver(note_revision_no_rels, unit, string, option(string)),
      title:
        Config.resolver(note_revision_no_rels, unit, string, option(string)),
    };
  };
  module User_identity_type_no_rels = {
    type t = {
      user_identity_type:
        Config.resolver(
          user_identity_type_no_rels,
          unit,
          string,
          option(string),
        ),
    };
  };
  module Query_root = {
    type t = {
      note:
        Config.resolver(
          query_root,
          {
            .
            "limit": option(int),
            "offset": option(int),
            "order_by": option(array(note_order_by)),
            "where": option(note_bool_exp),
          },
          note,
          array(note),
        ),
      note_revision:
        Config.resolver(
          query_root,
          {
            .
            "limit": option(int),
            "offset": option(int),
            "order_by": option(array(note_revision_order_by)),
            "where": option(note_revision_bool_exp),
          },
          note_revision,
          array(note_revision),
        ),
      user:
        Config.resolver(
          query_root,
          {
            .
            "limit": option(int),
            "offset": option(int),
            "order_by": option(array(user_order_by)),
            "where": option(user_bool_exp),
          },
          user,
          array(user),
        ),
      user_identity:
        Config.resolver(
          query_root,
          {
            .
            "limit": option(int),
            "offset": option(int),
            "order_by": option(array(user_identity_order_by)),
            "where": option(user_identity_bool_exp),
          },
          user_identity,
          array(user_identity),
        ),
      user_identity_type:
        Config.resolver(
          query_root,
          {
            .
            "limit": option(int),
            "offset": option(int),
            "order_by": option(array(user_identity_type_order_by)),
            "where": option(user_identity_type_bool_exp),
          },
          user_identity_type,
          array(user_identity_type),
        ),
    };
  };
  module User_identity_type = {
    type t = {
      user_identity_type:
        Config.resolver(user_identity_type, unit, string, option(string)),
    };
  };
  module User_identity = {
    type t = {
      data: Config.resolver(user_identity, unit, jsonb, option(jsonb)),
      identity_id:
        Config.resolver(user_identity, unit, string, option(string)),
      identity_type:
        Config.resolver(user_identity, unit, string, option(string)),
      user: Config.resolver(user_identity, unit, user, option(user)),
      user_id: Config.resolver(user_identity, unit, string, option(string)),
    };
  };
  module User_no_rels = {
    type t = {
      avatar: Config.resolver(user_no_rels, unit, string, option(string)),
      created_at:
        Config.resolver(
          user_no_rels,
          unit,
          timestamptz,
          option(timestamptz),
        ),
      email: Config.resolver(user_no_rels, unit, string, option(string)),
      id: Config.resolver(user_no_rels, unit, string, option(string)),
      name: Config.resolver(user_no_rels, unit, string, option(string)),
      updated_at:
        Config.resolver(
          user_no_rels,
          unit,
          timestamptz,
          option(timestamptz),
        ),
      username: Config.resolver(user_no_rels, unit, string, option(string)),
    };
  };
  module User_mutation_response = {
    type t = {
      affected_rows: Config.resolver(user_mutation_response, unit, int, int),
      returning:
        Config.resolver(
          user_mutation_response,
          unit,
          user_no_rels,
          array(user_no_rels),
        ),
    };
  };
  module Note_revision_mutation_response = {
    type t = {
      affected_rows:
        Config.resolver(note_revision_mutation_response, unit, int, int),
      returning:
        Config.resolver(
          note_revision_mutation_response,
          unit,
          note_revision_no_rels,
          array(note_revision_no_rels),
        ),
    };
  };
  module Note_mutation_response = {
    type t = {
      affected_rows: Config.resolver(note_mutation_response, unit, int, int),
      returning:
        Config.resolver(
          note_mutation_response,
          unit,
          note_no_rels,
          array(note_no_rels),
        ),
    };
  };
  module Mutation_root = {
    type t = {
      delete_note:
        Config.resolver(
          mutation_root,
          {. "where": note_bool_exp},
          note_mutation_response,
          option(note_mutation_response),
        ),
      delete_note_revision:
        Config.resolver(
          mutation_root,
          {. "where": note_revision_bool_exp},
          note_revision_mutation_response,
          option(note_revision_mutation_response),
        ),
      delete_user:
        Config.resolver(
          mutation_root,
          {. "where": user_bool_exp},
          user_mutation_response,
          option(user_mutation_response),
        ),
      delete_user_identity:
        Config.resolver(
          mutation_root,
          {. "where": user_identity_bool_exp},
          user_identity_mutation_response,
          option(user_identity_mutation_response),
        ),
      delete_user_identity_type:
        Config.resolver(
          mutation_root,
          {. "where": user_identity_type_bool_exp},
          user_identity_type_mutation_response,
          option(user_identity_type_mutation_response),
        ),
      insert_note:
        Config.resolver(
          mutation_root,
          {
            .
            "objects": array(note_insert_input),
            "on_conflict": option(note_on_conflict),
          },
          note_mutation_response,
          option(note_mutation_response),
        ),
      insert_note_revision:
        Config.resolver(
          mutation_root,
          {
            .
            "objects": array(note_revision_insert_input),
            "on_conflict": option(note_revision_on_conflict),
          },
          note_revision_mutation_response,
          option(note_revision_mutation_response),
        ),
      insert_user:
        Config.resolver(
          mutation_root,
          {
            .
            "objects": array(user_insert_input),
            "on_conflict": option(user_on_conflict),
          },
          user_mutation_response,
          option(user_mutation_response),
        ),
      insert_user_identity:
        Config.resolver(
          mutation_root,
          {
            .
            "objects": array(user_identity_insert_input),
            "on_conflict": option(user_identity_on_conflict),
          },
          user_identity_mutation_response,
          option(user_identity_mutation_response),
        ),
      insert_user_identity_type:
        Config.resolver(
          mutation_root,
          {
            .
            "objects": array(user_identity_type_insert_input),
            "on_conflict": option(user_identity_type_on_conflict),
          },
          user_identity_type_mutation_response,
          option(user_identity_type_mutation_response),
        ),
      update_note:
        Config.resolver(
          mutation_root,
          {
            .
            "_append": option(note_append_input),
            "_delete_at_path": option(note_delete_at_path_input),
            "_delete_elem": option(note_delete_elem_input),
            "_delete_key": option(note_delete_key_input),
            "_prepend": option(note_prepend_input),
            "_set": option(note_set_input),
            "where": note_bool_exp,
          },
          note_mutation_response,
          option(note_mutation_response),
        ),
      update_note_revision:
        Config.resolver(
          mutation_root,
          {
            .
            "_append": option(note_revision_append_input),
            "_delete_at_path": option(note_revision_delete_at_path_input),
            "_delete_elem": option(note_revision_delete_elem_input),
            "_delete_key": option(note_revision_delete_key_input),
            "_prepend": option(note_revision_prepend_input),
            "_set": option(note_revision_set_input),
            "where": note_revision_bool_exp,
          },
          note_revision_mutation_response,
          option(note_revision_mutation_response),
        ),
      update_user:
        Config.resolver(
          mutation_root,
          {
            .
            "_set": option(user_set_input),
            "where": user_bool_exp,
          },
          user_mutation_response,
          option(user_mutation_response),
        ),
      update_user_identity:
        Config.resolver(
          mutation_root,
          {
            .
            "_append": option(user_identity_append_input),
            "_delete_at_path": option(user_identity_delete_at_path_input),
            "_delete_elem": option(user_identity_delete_elem_input),
            "_delete_key": option(user_identity_delete_key_input),
            "_prepend": option(user_identity_prepend_input),
            "_set": option(user_identity_set_input),
            "where": user_identity_bool_exp,
          },
          user_identity_mutation_response,
          option(user_identity_mutation_response),
        ),
      update_user_identity_type:
        Config.resolver(
          mutation_root,
          {
            .
            "_set": option(user_identity_type_set_input),
            "where": user_identity_type_bool_exp,
          },
          user_identity_type_mutation_response,
          option(user_identity_type_mutation_response),
        ),
    };
  };
  module User_identity_mutation_response = {
    type t = {
      affected_rows:
        Config.resolver(user_identity_mutation_response, unit, int, int),
      returning:
        Config.resolver(
          user_identity_mutation_response,
          unit,
          user_identity_no_rels,
          array(user_identity_no_rels),
        ),
    };
  };
  module Note_no_rels = {
    type t = {
      created_at:
        Config.resolver(
          note_no_rels,
          unit,
          timestamptz,
          option(timestamptz),
        ),
      data: Config.resolver(note_no_rels, unit, jsonb, option(jsonb)),
      id: Config.resolver(note_no_rels, unit, string, option(string)),
      title: Config.resolver(note_no_rels, unit, string, option(string)),
      updated_at:
        Config.resolver(
          note_no_rels,
          unit,
          timestamptz,
          option(timestamptz),
        ),
      user_id: Config.resolver(note_no_rels, unit, string, option(string)),
    };
  };
  module User_identity_type_mutation_response = {
    type t = {
      affected_rows:
        Config.resolver(user_identity_type_mutation_response, unit, int, int),
      returning:
        Config.resolver(
          user_identity_type_mutation_response,
          unit,
          user_identity_type_no_rels,
          array(user_identity_type_no_rels),
        ),
    };
  };
  type t = {
    note_revision: Note_revision.t,
    user: User.t,
    subscription_root: Subscription_root.t,
    user_identity_no_rels: User_identity_no_rels.t,
    note: Note.t,
    note_revision_no_rels: Note_revision_no_rels.t,
    user_identity_type_no_rels: User_identity_type_no_rels.t,
    query_root: Query_root.t,
    user_identity_type: User_identity_type.t,
    user_identity: User_identity.t,
    user_no_rels: User_no_rels.t,
    user_mutation_response: User_mutation_response.t,
    note_revision_mutation_response: Note_revision_mutation_response.t,
    note_mutation_response: Note_mutation_response.t,
    mutation_root: Mutation_root.t,
    user_identity_mutation_response: User_identity_mutation_response.t,
    note_no_rels: Note_no_rels.t,
    user_identity_type_mutation_response: User_identity_type_mutation_response.t,
  };
};
