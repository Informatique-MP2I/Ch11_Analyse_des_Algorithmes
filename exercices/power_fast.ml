let rec power_fast base n =
  if n = 0 then
    1.0
  else
  if n mod 2 = 1 then
    base *. power_fast (base *. base) (n / 2)
  else
    power_fast (base *. base) (n / 2)
