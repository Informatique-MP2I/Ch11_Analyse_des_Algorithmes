// Function to increment the binary number represented by an array
void incr(int binary[], int n) {
  int i = n - 1;
  // Start with the least significant bit
  while (i >= 0 && binary[i]) {
    // Reset the current bit to 0 if it's 1
    binary[i] = 0;
    // Move to the next bit
    i--; 
  }
  if (i >= 0) {
    // Current bit = 1 if it's not at the end of the array
    binary[i] = 1; 
  }
}
