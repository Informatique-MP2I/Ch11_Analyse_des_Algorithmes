#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

/*
  Function to perform binary search on a sorted array.
  in :
  - t[] : An array of integers which is already sorted in ascending order.
  - n : The size of the array t[].
  - target : The integer value that the function is trying to find in the array t[].
  precond :
  - The array t[] must be sorted in non-decreasing order before calling.
  - n should correctly represent the number of elements in t[]. 
  out :
  - integer value : If the target is found in the array t[], the function returns the index of target within t[]. If the target is not found, the function returns -1.
*/
int binary_search(int t[], int n, int target) {
  int low = 0; 
  int high = n - 1;
    
  while (low <= high) {
    int mid = low + (high - low) / 2;

    // If the target is found in the array
    if (t[mid] == target) {
      return mid; 
    }

    // Adjust the index of the search range
    if (t[mid] < target) {
      low = mid + 1; 
    }
    else {
      high = mid - 1; 
    }
  }

  // Target is not found in the array
  return -1;
}

/* Auxiliary function to comapre two elements*/
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/*
  in :
  - n : The size of the array to be created. This integer determines how many elements will be in the array that the binary search algorithm will search through.
  out :
  - time_spent : The function returns a double value representing the execution time of the binary_search function in seconds.
 */
double measure_execution_time(int n) {
  int *t = (int *)malloc(n * sizeof(int));
  assert(t!= NULL);
  // Seed the random number generator
  srand(time(NULL));
  
  // Initialize array with random sorted values
  for (int i = 0; i < n; i++) {
    t[i] = i + 25; 
  }

  int target = t[rand() % n]; 

  // Calculate execution time
  struct timespec start, end;
  long long int time_spent_ns;
  
  // Start the stopwatch 
  clock_gettime(CLOCK_MONOTONIC, &start);
  for (int i=0;i<1000;i++)
    binary_search(t, n, target);
  
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
    printf("Binary search execution time for n=%d: %.10f seconds\n", ns[i], time_spent); 
  }
  
  return 0;
}
