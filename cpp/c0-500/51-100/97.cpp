class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            int m = s1.length(), n = s2.length(), o = s3.length();
            
            // If the lengths don't add up, return false
            if (m + n != o) return false;
            
            // Initialize DP table
            vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
            
            // Base case: Empty s1 and s2 can form empty s3
            dp[0][0] = true;
            
            // Fill the DP table
            for (int i = 0; i <= m; ++i) {
                for (int j = 0; j <= n; ++j) {
                    // If we can take from s1 and match s3
                    if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                    // If we can take from s2 and match s3
                    if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                        dp[i][j] = dp[i][j] || dp[i][j - 1];
                    }
                }
            }
            
            // Return the result stored in the bottom-right cell
            return dp[m][n];
        }
    };
    