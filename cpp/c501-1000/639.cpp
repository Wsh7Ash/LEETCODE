class Solution {
    public:
        int numDecodings(string s) {
            int MOD = 1e9 + 7;
            int n = s.size();
            vector<long long> dp(n + 1, 0);
            dp[0] = 1;
    
            if(s[0] == '*'){
                dp[1] = 9;
            }else if(s[0] == '0'){
                dp[1] = 0;
            }else{
                dp[1] = 1;
            }
    
            for(int i = 2; i <= n; i++){
                char cur = s[i-1];
                char prev = s[i-2];
                if(cur == '*'){
                    dp[i] += 9 * dp[i-1];
                }else if(cur != '0'){
                    dp[i] += dp[i-1];
                }
                if(prev == '*'){
                    if(cur == '*'){
                        dp[i] += 15 * dp[i-2];
                    }else if(cur <= '6'){
                        dp[i] += 2 * dp[i-2];
                    }else{
                        dp[i] += dp[i-2];
                    }
                }else if(prev == '1'){
                    if(cur == '*'){
                        dp[i] += 9 * dp[i-2];
                    }else{
                        dp[i] += dp[i - 2];
                    }
                }else if(prev == '2'){
                    if(cur == '*'){
                        dp[i] += 6 * dp[i-2];
                    }else if(cur <= '6'){
                        dp[i] += dp[i-2];
                    }
                }
                dp[i] %= MOD;
            }
            return dp[n];
        }
        
    };