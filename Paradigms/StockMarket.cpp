// beecrowd 1932 - StockMarket

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, c;

    // Read the number of days and the fixed commission fee for buying a stock
    cin >> n >> c;  

    vector<int> prices(n);

    // Read the stock prices for each day
    for (int i = 0; i < n; i++) {
        cin >> prices[i];  // Stock price on day i
    }

    // Initialize variables to track the maximum and minimum profit
    int maxProfit = 0;  // Maximum profit the investor can achieve
    int minProfit = -prices[0] - c;  // Minimum profit (considering the cost of buying on the first day)

    // Loop through the days starting from the second day
    for (int i = 1; i < n; i++) {
        // Calculate the maximum profit if the investor sells on day i
        maxProfit = max(maxProfit, minProfit + prices[i]);

        // Update the minimum profit by considering if the investor buys at the current price (after considering the commission)
        minProfit = max(minProfit, maxProfit - prices[i] - c);
    }

    // Output the maximum profit the investor could have made
    cout << maxProfit << endl;

    return 0;
}
