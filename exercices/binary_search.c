#include <stdio.h>

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

/* Test function */
int main(int argc, char **argv) {
  int t[] = {2, 4, 6, 8, 10, 12, 14}; 
  int n = 7; 
  int target = 10;

  // Perform binary search for the target
  int result = binary_search(t, n, target);
  if (result != -1) {
    printf("Element found at index: %d\n", result);
  } else {
    printf("Element not found in the array.\n");
  }

  return 0;
}
