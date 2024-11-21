// beecrowd 1088 - Bubbles And Buckets

#include <iostream>
#include <vector>
using namespace std;

// Function that counts the number of moves required to sort the array
int countMoves(int arr[], int n) {
    int moveCount = 0;  // Variable to count the number of moves
    for (int i = 0; i < n; i++) {
        // While the current element is not in its correct position
        while (arr[i] != i + 1) {
            // Swap the element to its correct position
            swap(arr[i], arr[arr[i] - 1]);
            moveCount++;  // Increment move count
        }
    }
    return moveCount;
}

int main() {
    int n = 1;
    vector<string> winnerList;  // List to store winners

    // Process multiple test cases until a line with 0 is encountered
    while (n > 0) {
        cin >> n;
        if (n == 0) {  // Exit condition
            break;
        }

        // Array to store the permutation
        int perm[n];
        for (int i = 0; i < n; i++) {
            cin >> perm[i];  // Input the permutation
        }

        // Count the number of moves required to sort the array
        int moveCount = countMoves(perm, n);

        // Determine the winner based on the number of moves
        if (moveCount == 0 || moveCount % 2 == 0) {
            winnerList.push_back("Carlos");  // Carlos wins if the number of moves is even
        } else {
            winnerList.push_back("Marcelo");  // Marcelo wins if the number of moves is odd
        }
    }

    // Output the winner for each test case
    int size = winnerList.size();
    for (int i = 0; i < size; i++) {
        cout << winnerList[i] << endl;  // Print each winner
    }

    return 0;
}
