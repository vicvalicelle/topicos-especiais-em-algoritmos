// beecrowd 1310 - Profit

#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the maximum profit George can make
int circusProfit(int days, int dailyCost, vector<int>& revenue) {
    int maxProfit = 0;  // Variable to store the maximum profit found
    int currentProfit = 0;  // Variable to track the profit for the current period

    // Loop through each day to compute the profit for different periods
    for (int i = 0; i < days; ++i) {
        // Calculate the profit for the current day by adding the revenue and subtracting the daily cost
        // If the profit becomes negative, start a new period (set currentProfit to 0)
        currentProfit = max(0, currentProfit + revenue[i] - dailyCost);
        
        // Update the maximum profit if the current profit is higher
        maxProfit = max(maxProfit, currentProfit);
    }

    return maxProfit;  // Return the maximum profit found
}

int main() {
    int days;  // Number of days George can bring his circus to the city
    int dailyCost;  // Daily cost to maintain the circus in the city

    // Loop to process multiple test cases
    while (cin >> days) {
        cin.ignore();  // Ignore the newline after reading the number of days

        // Read the daily cost
        cin >> dailyCost;

        // Create a vector to store the revenue for each day
        vector<int> revenue(days);
        
        // Read the revenue for each day
        for (int i = 0; i < days; ++i) {
            cin >> revenue[i];
        }

        // Call the function to calculate the maximum profit and print the result
        int result = circusProfit(days, dailyCost, revenue);
        cout << result << endl;
    }

    return 0;
}
