// beecrowd 2663 - Phase

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;  // n is the number of competitors, k is the minimum number of competitors to qualify
    int score;  // To store the score of each competitor

    cin >> n >> k;  // Read the number of competitors and the minimum number of qualifiers

    vector<int> competitors;  // Vector to store the scores of the competitors

    // Read the scores of the competitors
    for (int i = 0; i < n; ++i) {
        cin >> score;
        competitors.push_back(score);  // Store each score in the vector
    }
  
    // Sort the competitors' scores in descending order (highest score first)
    sort(competitors.rbegin(), competitors.rend());
  
    int qualified = k;  // Initially assume that the first k competitors qualify
  
    // Check if there are ties in the k-th position, and include all tied competitors
    while (qualified < n && competitors[qualified] == competitors[k - 1]) {
        qualified++;  // Increment the number of qualifiers if there is a tie
    }

    cout << qualified << endl;  // Print the total number of qualified competitors
  
    return 0;
}
