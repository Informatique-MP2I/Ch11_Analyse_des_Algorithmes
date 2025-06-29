#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

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

/*
  in :
  - n : The size of the array to be created. This integer determines how many elements will be in the array that the binary search algorithm will search through.
  out :
  - time_spent : The function returns a double value representing the execution time of the dot_product function in seconds.
 */
double measure_execution_time(int n) {
  double *vec1 = (double *)malloc(n * sizeof(double));
  assert(vec1 != NULL);
  double *vec2 = (double *)malloc(n * sizeof(double));
  assert(vec2 != NULL);
  // Seed the random number generator
  srand(time(NULL)); 
  
  // Initialize array with random values
  for (int i = 0; i < n; i++) {
    vec1[i] = (double)(rand() % (n * 10));
    vec2[i] = (double)(rand() % (n * 10));
  }

  // Calculate execution time
  struct timespec start, end;
  long long int time_spent_ns;
 
  // Start the stopwatch
  clock_gettime(CLOCK_MONOTONIC, &start);
  for (int i=0;i<1000;i++)
    dot_product(vec1, vec2, n);
  
  // Stop the stopwatch
  clock_gettime(CLOCK_MONOTONIC, &end);
  
  // Calculate the elapsed time in nanoseconds
  time_spent_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
  
  free(vec1);
  free(vec2);
  return (double)time_spent_ns/1000000000;
}

/* Main function */
int main(int argc, char **argv) {
   // Different values of n
  int ns[] = {10, 100, 1000, 10000, 1000000}; 
  
  for (int i = 0; i < 5; i++) {
    // Measure execution time for each n
    double time_spent = measure_execution_time(ns[i]);  
    printf("Dot product execution time for n=%d: %f seconds\n", ns[i], time_spent); 
  }
  
  return 0;
}
