class Solution {
    public:
        int numWays(vector<string>& words, string target) {
            int MOD = 1e9+7;
            int wordLen = words[0].size();
            int n = words.size();
            int m = target.size();
    
            vector<vector<long long>> freq(26, vector<long long>(wordLen, 0));
            for(int j = 0; j < wordLen; j++){
                for(int i = 0; i < n; i++){
                    freq[words[i][j] - 'a'][j]++;
                }
            }
            vector<long long> dp(m + 1, 0);
            dp[0] = 1;
    
            for(int j = 0; j < wordLen; j++){
                for(int i = m - 1; i >= 0; i--){
                    long long count = freq[target[i] - 'a'][j];
                    dp[i+1] = (dp[i+1] + dp[i] * count) % MOD;
                }
            }
            return dp[m];
        }
    };