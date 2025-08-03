class Solution {
    public:
        int numDupDigitsAtMostN(int n) {
            string s = to_string(n);
            int len = s.length();
            int dp[len][1 << 10][2];
            memset(dp, -1, sizeof(dp));
    
            function<int(int, int, bool)> dfs = [&](int pos, int mask, bool tight) -> int{
                if(pos == len) return 1;
    
                if(dp[pos][mask][tight] != -1) return dp[pos][mask][tight];
    
                int limit = tight ? s[pos] - '0' : 9;
                int res = 0;
                for(int d = 0; d <= limit; d++){
                    bool new_tight = tight && (d == limit);
                    if(mask & (1 << d)){
                        continue;
                    } 
                    int new_mask = (mask == 0 && d == 0) ? mask : (mask | (1 << d));
                    res += dfs(pos + 1, new_mask, new_tight);
                }
                dp[pos][mask][tight] = res;
                return res;
            };
    
            int tnwr = dfs(0,0, true);
            return n - tnwr + 1;
        }
    };