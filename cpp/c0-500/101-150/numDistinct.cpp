#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<unsigned int>> dp(m + 1, vector<unsigned int>(n + 1, 0));

        // Base case: An empty target string is a subsequence of any prefix of s
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;
    cout << "Test 1: " << sol.numDistinct("rabbbit", "rabbit") << endl; // Output: 3
    cout << "Test 2: " << sol.numDistinct("babgbag", "bag") << endl;    // Output: 5
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;  // Large prime to avoid overflow
        int m = s.length(), n = t.length();
        vector<unsigned long long> dp(n + 1, 0);  // Use larger data type for dp

        dp[0] = 1;  // Base case: empty t is a subsequence of any prefix of s

        for (int i = 1; i <= m; i++) {
            // Traverse backward to avoid overwriting during the same iteration
            for (int j = n; j > 0; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = (dp[j] + dp[j - 1]) % MOD;  // Take modulo to avoid overflow
                }
            }
        }

        return dp[n];  // The result is stored in dp[n]
    }
};

int main() {
    Solution sol;
    cout << "Test 1: " << sol.numDistinct("rabbbit", "rabbit") << endl; // Output: 3
    cout << "Test 2: " << sol.numDistinct("babgbag", "bag") << endl;    // Output: 5
    return 0;
}
