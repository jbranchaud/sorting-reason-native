exception Invariant_violation(string);

let expect = condition =>
  switch (assert(condition)) {
  | exception (Assert_failure(exn_data)) =>
    let (msg, line, _) = exn_data;
    let exn_msg = Printf.sprintf("Invariant Violation: %s:%i", msg, line);
    raise(Invariant_violation(exn_msg));
  | _ => ignore
  };