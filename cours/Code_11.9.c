int linear_search(int t[], int n, int target) {
  for (int i = 0; i < n; i++) {
    if (t[i] == target)
      return i;
  }
  return -1;
}
