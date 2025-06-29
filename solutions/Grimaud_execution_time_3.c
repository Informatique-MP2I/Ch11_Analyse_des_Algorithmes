#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

/*
  Function to check if an array contains duplicates.
  in:
  - t[]: An array of integers.
  - n: The size of the array t[].
  precond:
  - n should correctly represent the number of elements in t[].
  out:
  - boolean value: true if any duplicates are found within the array t[]. false if no duplicates are present in the array.
*/
bool contains_duplicates(int t[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      // If a duplicate is found
      if (t[i] == t[j]) {
	return true;
      }
    }
  }
  // If no duplicates are found
  return false;
}

/*
  Function to measure the execution time of the contains_duplicates function.
  in:
  - n: The size of the array to be created.
  out:
  - time_spent: The execution time of the contains_duplicates function in seconds as a double value.
*/
double measure_execution_time(int n) {
  int *t = (int *)malloc(n * sizeof(int));
  assert(t != NULL);
  // Seed the random number generator
  srand(time(NULL));
  
  // Initialize array with random values
  for (int i = 0; i < n; i++) {
    t[i] = rand() % (n * 10);
  }

  // Calculate execution time
  struct timespec start, end;
  long long int time_spent_ns;
  
  // Start the stopwatch
  clock_gettime(CLOCK_MONOTONIC, &start);
  for (int i=0;i<1000;i++)
    contains_duplicates(t, n);
  
  // Stop the stopwatch
  clock_gettime(CLOCK_MONOTONIC, &end);
  
  // Calculate the elapsed time in nanoseconds
  time_spent_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
  
  free(t);
  return (double)(time_spent_ns)/1000000000;
}

/* Main function */
int main(int argc, char **argv) {
  // Different values of n
  int ns[] = {10, 100, 1000, 10000, 1000000};

  for (int i = 0; i < 5; i++) {
    // Measure execution time for each n
    double time_spent = measure_execution_time(ns[i]);
    printf("Duplicates search execution time for n=%d: %f seconds\n", ns[i], time_spent);
  }

  return 0;
}
