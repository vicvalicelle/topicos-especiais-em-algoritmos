// beecrowd 1286 - Motoboy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, p;

    // Loop until we read the end condition (n = 0)
    while (cin >> n) {
        if (n == 0) break;  // End of input signal

        cin >> p;  // Read the maximum number of pizzas Roberto can deliver

        // Vector to store each order with its delivery time and number of pizzas
        vector<pair<int, int>> orders(n);

        // Read each order's delivery time and number of pizzas
        for (int i = 0; i < n; i++) {
            cin >> orders[i].first >> orders[i].second;
        }

        // Sort the orders based on delivery time in descending order
        // This ensures that we prioritize the orders that take the longest time to deliver
        sort(orders.begin(), orders.end(), greater<pair<int, int>>());

        // Create a dynamic programming table to store the maximum time Roberto will take for each possible number of pizzas
        vector<int> dp(p + 1, 0);

        // Dynamic programming to find the best combination of orders Roberto should deliver
        for (int i = 0; i < n; i++) {
            for (int j = p; j >= orders[i].second; j--) {
                // We try to include the current order and check if it improves the delivery time
                dp[j] = max(dp[j], dp[j - orders[i].second] + orders[i].first);
            }
        }

        // The result is the total time that Roberto will take for delivering the selected orders
        int totalTime = dp[p];

        // Output the result in the specified format
        cout << totalTime << " min." << endl;
    }

    return 0;
}
