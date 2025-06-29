double power_fast(double base, int n) {
  double result = 1.0;
  int i=n;
  while (i > 0) {
    if (i % 2 == 1) {
      result = result * base;
    }
    base = base * base;
    i = i / 2;
  }
  return result;
}
