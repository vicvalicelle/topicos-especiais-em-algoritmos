// beecrowd 3428 - Eliminating Ballons

#include <iostream>
#include <unordered_map> // Insertion, removal, and search in an unordered_map have an average time complexity of O(1)

using namespace std;

int main() { // Time complexity is O(N), where N is the number of balloons.
    int n, b; // n is the number of balloons, b is the height of the current balloon
    cin >> n;

    unordered_map<int, int> balloons; // Map to track the number of arrows needed for each height

    int arrows = 0; // Counter for the number of arrows required
    for (int i = 0; i < n; i++) {
        cin >> b; // Read the height of the current balloon

        // Check if there is an arrow already available at the current balloon's height
        if (balloons.find(b) != balloons.end() && balloons[b] > 0) {
              balloons[b]--; // Use one arrow for the balloon at this height
        } else {
            arrows++; // If no arrow is available for this height, fire a new arrow
        }

        // After shooting, the arrow continues to the next height (height - 1)
        balloons[b - 1]++; // Add an arrow to the next height's counter
    }

    cout << arrows << endl; // Output the total number of arrows fired
    return 0;
}
