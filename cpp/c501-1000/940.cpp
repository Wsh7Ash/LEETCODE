class Solution {
    public:
        int distinctSubseqII(string s) {
            const int MOD = 1e9 + 7;
            int n = s.length();
            
            vector<long long> dp(n + 1, 0);
            dp[0] = 1; 
            
            unordered_map<char, int> lastPos;
            
            for (int i = 0; i < n; i++) {
                char c = s[i];
    
                dp[i + 1] = (2 * dp[i]) % MOD;
                
                if (lastPos.find(c) != lastPos.end()) {
                    int prevPos = lastPos[c];
                    dp[i + 1] = (dp[i + 1] - dp[prevPos] + MOD) % MOD;
                }
                
                lastPos[c] = i;
            }
            
            return (dp[n] - 1 + MOD) % MOD;
        }
    };