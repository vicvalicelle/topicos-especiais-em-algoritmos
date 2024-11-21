// beecrowd 1941 - Palindrome
// Time limit exceeded

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;  // Read the string (potential palindrome)
    
    int n;
    cin >> n;  // Read the number of special positions
    
    vector<int> specialPositions(n);  // Vector to store the special positions
    for (int i = 0; i < n; i++) {
        cin >> specialPositions[i];  // Read each special position
        specialPositions[i]--;  // Convert to 0-based indexing
    }

    int len = s.size();
    
    // Create DP tables:
    // dp[i][j] will store the length of the longest palindromic subsequence between indices i and j
    // count[i][j] will store the number of special positions in the subsequence between indices i and j
    vector<vector<int>> dp(len, vector<int>(len, 0));
    vector<vector<int>> count(len, vector<int>(len, 0));

    // Initialize DP tables for subsequences of length 1
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;  // Single character is a palindrome of length 1
        for (int pos : specialPositions) {
            if (pos == i) {
                count[i][i] = 1;  // If the position is special, increment the count
            }
        }
    }

    // Fill the DP tables using dynamic programming
    for (int l = 2; l <= len; l++) {  // l is the length of the subsequence
        for (int i = 0; i < len - l + 1; i++) {  // i is the starting index
            int j = i + l - 1;  // j is the ending index
            if (s[i] == s[j]) {  // If the characters match, the subsequence can expand
                dp[i][j] = dp[i + 1][j - 1] + 2;  // Increase the length of the palindrome by 2
                count[i][j] = count[i + 1][j - 1];  // Keep the count of special positions from the inner subsequence
                for (int pos : specialPositions) {  // Update the special position count if applicable
                    if (pos >= i && pos <= j) {
                        count[i][j]++;
                    }
                }
            } else {  // If characters don't match, choose the best subsequence between i+1 and j, or i and j-1
                if (dp[i + 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i + 1][j];
                    count[i][j] = count[i + 1][j];
                } else if (dp[i + 1][j] < dp[i][j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                    count[i][j] = count[i][j - 1];
                } else {  // If both subsequences have the same length, choose the one with the most special positions
                    dp[i][j] = dp[i + 1][j];
                    count[i][j] = max(count[i + 1][j], count[i][j - 1]);
                }
            }
        }
    }

    // Find the longest palindromic subsequence that contains all special positions
    int maxLen = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (count[i][j] == n && dp[i][j] > maxLen) {  // If the subsequence contains all special positions
                maxLen = dp[i][j];  // Update the maximum length
            }
        }
    }

    cout << maxLen << endl;  // Output the maximum length of the palindrome subsequence

    return 0;
}
