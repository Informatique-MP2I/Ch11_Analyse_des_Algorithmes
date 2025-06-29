#include <stdio.h>

// First attemp of this function of O(n^2) complexity
int maximum_subarray(int *t, int n){
    int max = 0;
    int s;

    for(int i=0;i<n;i++){
      s = 0;
      for(int j=i;j<n;j++){
	s = s + t[j];
	if (s > max)
	  max = s;	
      }
    }
    return max;
}

// Second attemp of this function of O(n) complexity
// Algorithme de Jay Kadane
int maximum_subarray2(int *t, int n){
    int max = 0;
    int maxhere = 0;
  
    for(int i=0;i<n;i++){
      maxhere = maxhere + t[i];
      if(maxhere < 0)
	maxhere = 0;
      if(maxhere > max)
	max = maxhere;
    }
    return max;
}

int main(int argc, char **argv) {
  int t[7]={-1,9,-4,7,-8,5,-3};
  int sum = 0;
  
  sum = maximum_subarray(t,7);
  printf("Maximum subarray has the value : %d\n", sum);
  return 0;
}
