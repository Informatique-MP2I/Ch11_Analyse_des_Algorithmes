let rec print_numbers n =
  Printf.printf "n = %d\n" n;
  (* Recursive call with the next number in the progression *)
  print_numbers (n + 1)
let () =
  (* Start printing numbers from 0 *)
  print_numbers 0
