#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    // Create a DP table of size (m+1) x (n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Base cases
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i; // Delete all characters in word1
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j; // Insert all characters of word2
    }

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                // Characters match, no operation needed
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Choose the minimum of insert, delete, or replace
                dp[i][j] = 1 + min({dp[i][j - 1],    // Insert
                                    dp[i - 1][j],    // Delete
                                    dp[i - 1][j - 1]}); // Replace
            }
        }
    }

    // The result is in dp[m][n]
    return dp[m][n];
}

int main() {
    // Test cases
    cout << minDistance("horse", "ros") << endl;          // Output: 3
    cout << minDistance("intention", "execution") << endl; // Output: 5
    cout << minDistance("abc", "def") << endl;            // Output: 3
    cout << minDistance("", "abc") << endl;               // Output: 3
    cout << minDistance("abc", "") << endl;               // Output: 3

    return 0;
}