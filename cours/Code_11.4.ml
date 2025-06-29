let can_cover points k length =
  let rec aux last_point used i =
    if i = Array.length points then
      used <= k
    else
    if points.(i) > last_point +. length then
      aux points.(i) (used + 1) (i + 1)
    else
      aux last_point used (i + 1)
  in
  aux points.(0) 1 1
let find_min_length points k =
  let threshold = 1e-6 in
  let rec aux l h =
    if h -. l < threshold then h
    else
      let mid = l +. (h -. l) /. 2.0 in
      if can_cover points k mid then
        aux l mid
      else
        aux mid h
  in
  aux 0.0 (points.(Array.length points - 1) -. points.(0))
let () =
  let points = [|1.0; 2.0; 3.5; 6.0; 7.5|] in
  let k = 2 in
  let min = find_min_length points k in
  Printf.printf "%f is the minimum length to cover points.\n" min
