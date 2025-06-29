#include <stdio.h>

/*
  Function to calculate the dot product of two vectors.
  in :
  - t[] : An array of integers.
  - n : The size of the array t[].
  precond :
  - n should correctly represent the number of elements in t[].
  out :
  - boolean value : true if the array t[] contains at least one pair of duplicate elements. false if no duplicates are found in the array.
*/
double dot_product(double vec1[], double vec2[], int n) {
  double result = 0.0; 

  for (int i = 0; i < n; i++) {
    result = result + vec1[i] * vec2[i];
  }

  return result;
}

/* Test function */
int main(int argc, char **argv) {
  double vec1[] = {1.0, 8.1, 3.0, 5.6};
  double vec2[] = {7.0, 4.3, 6.0, 3.2};
  int n = 4; 
  
  double result = dot_product(vec1, vec2, n);
  printf("The dot product is: %f\n", result);
  
  return 0;
}
