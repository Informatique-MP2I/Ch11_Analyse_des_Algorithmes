#include <stdio.h>
#include <stdbool.h>

/*
  Function to check if an array contains duplicates.
  in :
  - t[] : An array of integers.
  - n : The size of the array t[].
  precond :
  - n should correctly represent the number of elements in t[]. 
  out :
  - boolean value : true if any duplicates are found within the array t[]. false if no duplicates are present in the array.
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

/* Test function */
int main() {
  int t[] = {1, 2, 3, 4, 5, 1}; 
  int n = 6;

  // Check if the array contains duplicates
  if (contains_duplicates(t, n)) {
    printf("The array contains duplicates.\n");
  } else {
    printf("The array does not contain duplicates.\n");
  }

  return 0;
}
