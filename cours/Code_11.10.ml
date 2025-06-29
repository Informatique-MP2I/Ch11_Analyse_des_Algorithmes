let rec linear_search target lst index =
  if index >= List.length lst then
    (-1) 
  else if List.nth lst index = target then
    index 
  else
    linear_search target lst (index + 1) 
      
