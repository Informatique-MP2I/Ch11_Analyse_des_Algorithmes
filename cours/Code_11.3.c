#include <stdio.h>
#include <stdbool.h>
bool can_cover(double points[], int n, int k, double length) {
  double end = points[0] + length;
  int used = 1;
  for (int i = 1; i < n; i++)
    if (points[i] > end) {
      end = points[i] + length;
      used++;
    }
  return used <= k;
}
double find_min_length(double points[], int n, int k) {
  double l = 0.0;
  double h = points[n-1] - points[0]; // h is a valid value
  double mid;
  double threshold = 1e-6;  // this is a sufficient precision.
  while (h - l > threshold) {
    mid = l + (h - l) / 2.0;
    if (can_cover(points, n, k, mid))
      h = mid;
    else
      l = mid;
  }
  return h;
}
int main() {
    double points[] = {1.0, 2.0, 3.5, 6.0, 7.5}; // Points sample
    int n = 5; // Number of points
    int k = 1; // Number of segments
    double min = find_min_length(points, n, k);
    printf("%lf is the minimum length to cover points.\n", min);
    return 0;
}
