#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
int main(int argc, char **argv) {
  // Initialize an unsigned integer to its maximum possible value
  const unsigned int init_n = UINT_MAX; // 2^32-1 = 4 294 967 295
  // Loop that increments n indefinitely
  for(unsigned int n=init_n;n <= UINT_MAX;n++) { 
    printf("n = %u\n", n);
    if (n == 0) {
      printf("Overflow! Back to zero.\n");
    }
  }
  return 0; // end never reached: loop condition is always true
}
