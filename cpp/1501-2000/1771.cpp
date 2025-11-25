class Solution {
    public:
        int longestPalindrome(string word1, string word2) {
            int m = word1.length();
            int n = word2.length();
            string s = word1 + word2;
            int len = s.length();
            vector<vector<int>> dp(len, vector<int>(len, 0));
            for(int i = 0; i < len; i++){
                dp[i][i] = 1;
            }
    
            for(int l = 2; l <= len; l++){
                for(int i = 0; i <= len - l; i++){
                    int j = i + l - 1;
                    if(s[i] == s[j]){
                        if(l == 2){
                            dp[i][j] = 2;
                        }else{
                            dp[i][j] = dp[i + 1][j - 1] + 2;
                        }
                    }else{
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
    
            int res = 0;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(word1[i] == word2[j]){
                        res = max(res, dp[i][m + j]);
                    }
                }
            }
            return res;
        }
    };