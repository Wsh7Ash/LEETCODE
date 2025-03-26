class Solution {
    public:
        bool isScramble(string s1, string s2) {
            // If both strings are equal, they are trivially scrambled versions of each other
            if (s1 == s2) return true;
            
            // Length of the strings
            int n = s1.size();
            
            // Memoization table, initialized to false
            vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
            
            // Recursive function with memoization
            return dfs(s1, s2, 0, 0, n, dp);
        }
        
        bool dfs(const string& s1, const string& s2, int i, int j, int len, vector<vector<vector<int>>>& dp) {
            // Base case: If the lengths of the substrings are 0
            if (len == 0) return true;
    
            // If this state has been computed before, return the stored result
            if (dp[i][j][len] != -1) return dp[i][j][len];
            
            // If the substrings are equal, no need to recurse further
            if (s1.substr(i, len) == s2.substr(j, len)) {
                dp[i][j][len] = true;
                return true;
            }
            
            // Check if they are scramble versions of each other by trying all splits
            bool result = false;
            for (int k = 1; k < len; k++) {
                // Case 1: No swap - check if both parts match directly
                if (dfs(s1, s2, i, j, k, dp) && dfs(s1, s2, i + k, j + k, len - k, dp)) {
                    result = true;
                    break;
                }
                // Case 2: Swap the parts - check if the first part of s1 matches the second part of s2
                if (dfs(s1, s2, i, j + len - k, k, dp) && dfs(s1, s2, i + k, j, len - k, dp)) {
                    result = true;
                    break;
                }
            }
            
            // Store the result in dp table
            dp[i][j][len] = result;
            return result;
        }
    };
    