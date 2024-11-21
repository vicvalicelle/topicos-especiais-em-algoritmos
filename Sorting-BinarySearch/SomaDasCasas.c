// beecrowd 2422 - Soma das Casas

#include <stdio.h>

int main() {
  int n;          // Number of houses on the street
  int left;       // Left pointer
  int right;      // Right pointer
  int targetSum;  // The target sum (K) of house numbers
  int currentSum; // The sum of the elements at left and right pointers

  // Reading the number of houses (N)
  scanf("%d", &n);
  int arr[n]; // Array to store the house numbers

  // Reading the house numbers (sorted in ascending order)
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  left = 0;       // Initialize left pointer to the beginning of the list
  right = n - 1;  // Initialize right pointer to the end of the list

  // Reading the target sum (K) which is the sum of the house numbers where the toys are hidden
  scanf("%d", &targetSum);

  // Start searching for the two house numbers that add up to the targetSum (K)
  while(arr[left] < arr[right]) {
    currentSum = arr[left] + arr[right]; // Calculate the sum of elements at the left and right pointers

    // If the sum is greater than the targetSum, move the right pointer leftward
    if(currentSum > targetSum) {
      right--; // Decrease the right pointer to reduce the sum
    }
    // If the sum is less than the targetSum, move the left pointer rightward
    else if(currentSum < targetSum) {
      left++; // Increase the left pointer to increase the sum
    }
    // If the sum is equal to the targetSum, print the pair and break
    else {
      printf("%d %d\n", arr[left], arr[right]); // Print the house numbers where the toys are hidden
      break; // Exit the loop as the correct pair is found
    }
  }

  return 0; // End of the program
}
