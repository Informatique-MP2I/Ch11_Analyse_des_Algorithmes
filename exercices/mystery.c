bool mystery(int t1[], int t2[], int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (t1[i] == t2[j])
        return true;
  return false; 
}
