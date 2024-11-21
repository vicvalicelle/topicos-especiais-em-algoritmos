// beecrowd 1507 - Subsequences

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function that checks if a query is a subsequence of the main string
bool isSubsequence(const string& mainString, const string& query) {
    int mainStringIndex = 0;  // Index to traverse through the main string
    for (char c : query) {  // For each character in the query
        // Find the character 'c' in the mainString starting from mainStringIndex
        size_t pos = mainString.find(c, mainStringIndex);
        if (pos == string::npos) {  // If the character is not found
            return false;  // It's not a subsequence
        }
        mainStringIndex = pos + 1;  // Update the index to the next character after the found position
    }
    return true;  // All characters were found in the correct order, so it's a subsequence
}

int main() {
    int numTestCases;  // The number of test cases
    cin >> numTestCases;

    vector<string> results;  // To store the results of each query

    for (int i = 0; i < numTestCases; ++i) {
        string mainString;  // The main string for the current test case
        int numQueries;     // The number of queries for the current test case
        cin >> mainString;
        cin >> numQueries;

        vector<string> queries;  // To store all the queries for the current test case
        for (int j = 0; j < numQueries; ++j) {
            string query;  // An individual query string
            cin >> query;
            queries.push_back(query);  // Add the query to the queries list
        }

        // Check each query if it's a subsequence of the main string
        for (const auto& query : queries) {
            if (isSubsequence(mainString, query)) {
                results.push_back("Yes");  // If it's a subsequence, add "Yes" to the results
            } else {
                results.push_back("No");   // If it's not a subsequence, add "No"
            }
        }
    }

    // Print all the results for the queries
    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}
