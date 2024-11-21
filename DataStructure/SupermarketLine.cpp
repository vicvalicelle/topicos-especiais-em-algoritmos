// beecrowd 2065 - Supermarket Line

#include <iostream>
#include <vector>
#include <queue> // Priority queue: O(1) time, O(1) space for basic functions, but O(log N) for .push() and .pop() operations
using namespace std;

int main() { // Time complexity: O(cashiers + customers * log(cashiers))
    int cashiers; // Number of cashiers (employees at the checkout)
    int customers; // Number of customers
    int items;  // Number of items the current customer has in their basket
    int accumulatedTime; // Accumulated processing time for a cashier (after serving a customer)
    
    // Priority queue to store each cashier's current available time in ascending order (the smallest time at the top)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
    // Priority queue to store the final time of each cashier in descending order (for finding the time when the last customer is served)
    priority_queue<pair<int, int>> maxHeap;

    cin >> cashiers >> customers; // Read the number of cashiers and customers
    int processingTime[cashiers]; // Array to store the processing time per item for each cashier

    // Read the processing times for each cashier
    for (int i = 0; i < cashiers; i++) { // O(N)
        cin >> processingTime[i];
    }

    // Initialize the priority queue with each cashier's starting time as 0
    for (int i = 1; i <= cashiers; i++) { // Initialize the priority queue with (time, cashier_id)
        minHeap.push({0, i}); // O(log(N)) - Add each cashier with an initial time of 0
        maxHeap.push({0, i}); // O(log(N)) - Same for the second priority queue
    }

    // Process each customer
    for (int i = 0; i < customers; i++) {
        cin >> items; // Read the number of items for the current customer
        pair<int, int> cashier = minHeap.top(); // Get the cashier with the least accumulated time (the smallest value)
        minHeap.pop(); // O(log(N)) - Remove the top element, which is the least busy cashier
        
        // Calculate the time this cashier will take to process the current customer
        accumulatedTime = items * processingTime[cashier.second - 1] + cashier.first; // Time = items * cashier's processing time per item + accumulated time for the cashier
        // Update the cashier's time and push it back into the priority queue
        minHeap.push({accumulatedTime, cashier.second}); // O(log(N)) - Push updated time with cashier's ID
        maxHeap.push({accumulatedTime, cashier.second}); // O(log(N)) - Also push into the second priority queue to track the final processing times
    }

    // Output the time when the last customer will finish being served
    cout << maxHeap.top().first << endl; // O(1) - Get the top element from the second priority queue (the last finish time)

    return 0;
}
