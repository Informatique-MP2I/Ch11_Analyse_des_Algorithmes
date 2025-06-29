let rec power_naive base n =
  if n = 0 then
    1.0
  else
    base *. power_naive base (n - 1)
