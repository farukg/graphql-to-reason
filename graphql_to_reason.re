open Core;

let json_file_path =
  Command.Spec.Arg_type.create(filename =>
    switch (Sys.is_file(filename)) {
    | `Yes =>
      switch (Caml.Filename.extension(filename)) {
      | ".json" => filename
      | _ =>
        eprintf("'%s' is not a json file.\n%!", filename);
        exit(1);
      }
    | `No
    | `Unknown =>
      eprintf("'%s' is not a regular file.\n%!", filename);
      exit(1);
    }
  );

let output = (~outputFiles, ~result) => {
  let (formatter, oc) =
    switch (outputFiles) {
    | [target, ..._rest] =>
      let oc = Out_channel.create(target);
      (Format.formatter_of_out_channel(oc), Some(oc));
    | _ => (Format.std_formatter, None)
    };

  Reason_toolchain.RE.print_implementation_with_comments(formatter, result);

  Format.print_flush();

  switch (oc) {
  | Some(oc) => Out_channel.close(oc)
  | None => ()
  };
};

let fromFile =
  Command.Let_syntax.(
    Command.basic(
      ~summary="generate reason types from graphql_schema.json",
      {
        let%map_open filepath = anon("filepath" %: json_file_path)
        and outputFiles = anon(sequence("output_path" %: file));
        () => {
          let resultRead = Lib.(SchemaRead.File(filepath) |> SchemaRead.read);
          let result = Lib.(resultRead |> SchemaPrint.print);
          let result2 = Lib.(resultRead |> SchemaPrintJsT.print);
          // let resultRecord = Lib.(resultRead |> SchemaPrintRecord.print);
          let out2 =
            List.map(
              outputFiles,
              i => {
                let len = String.length(i);
                let rr = String.sub(i, 0, len - 3);
                rr ++ "_JsT.re";
              },
            );
          // let out3 =
          //   List.map(
          //     outputFiles,
          //     i => {
          //       let len = String.length(i);
          //       let rr = String.sub(i, 0, len - 3);
          //       rr ++ "_Record.re";
          //     },
          //   );
          output(~outputFiles, ~result);
          output(~outputFiles=out2, ~result=result2);
          // output(~outputFiles=out3, ~result=resultRecord);
        };
      },
    )
  );

Command.run(~build_info="", fromFile);