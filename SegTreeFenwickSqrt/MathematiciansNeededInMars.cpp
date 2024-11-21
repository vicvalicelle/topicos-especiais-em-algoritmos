// beecrowd 1804 - Mathematicians Needed in Mars

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// The time complexity of this solution is O((q + n) * sqrt(n)), where q is the number of queries and n is the number of buggies.

int main() {
    int num_buggies, index;
    char operation;

    // Read number of buggies
    cin >> num_buggies;

    vector<int> buggies(num_buggies + 1);  // To store the number of people in each buggy (1-based indexing)
    for (int i = 1; i <= num_buggies; i++) {
        cin >> buggies[i];  // Input the number of people in each buggy
    }

    // Square Root Decomposition
    // Divide the array of buggies into blocks of size sqrt(num_buggies) and store the sum of each block in a separate array 'block_sums'
    int block_size = (int)sqrt(num_buggies + .0) + 1;
    vector<int> block_sums(block_size);

    // Fill the block_sums array
    for (int i = 1; i <= num_buggies; ++i) {
        block_sums[i / block_size] += buggies[i];  // Add the buggy's people count to the corresponding block sum
    }

    // Process the operations
    while (cin >> operation >> index) {
        if (operation == 'a') {
            // Abduction: Set the buggy index to 0 (remove the buggy from the tour)
            int block = index / block_size;
            block_sums[block] -= buggies[index];  // Remove the buggy's people from the block sum
            buggies[index] = 0;  // Set the buggy's people count to 0
        } else if (operation == '?') {
            // Query: Calculate the number of people left in the buggies after the given buggy index
            int sum = 0;
            int block = index / block_size;

            // Sum the values from complete blocks
            for (int i = block + 1; i < block_size; ++i) {
                sum += block_sums[i];  // Add the sum of people in the complete blocks
            }

            // Sum the remaining elements within the block where 'index' is located
            for (int i = block * block_size + 1; i <= num_buggies; ++i) {
                sum += buggies[i];  // Add the people count for the remaining buggies
            }

            cout << sum << endl;  // Output the result of the query
        } else {
            break;  // End the loop if there are no valid operations
        }
    }

    return 0;
}
