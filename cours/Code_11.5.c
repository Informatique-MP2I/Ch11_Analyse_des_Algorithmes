double power_naive(double base, int n) {
  double result = 1.0;
  for (int i = 0; i < n; i++) {
    result = result * base;
  }
  return result;
}
