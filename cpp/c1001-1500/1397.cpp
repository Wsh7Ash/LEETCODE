class Solution {

    private:
        const int MOD = 1e9 + 7;
    
        vector<int> computeLPS(string& pattern){
            int m = pattern.length();
            vector<int> lps(m, 0);
            int len = 0;
            for(int i = 1; i < m; ){
                if(pattern[i] == pattern[len]){
                    lps[i++] = ++len;
                }else{
                    if(len != 0){
                        len = lps[len - 1];
                    }else{
                        lps[i++] = 0;
                    }
                }
            }
            return lps;
        }
    
    public:
        int findGoodStrings(int n, string s1, string s2, string evil) {
    
            int m = evil.length();
            vector<int> lps = computeLPS(evil);
    
            vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(
                2, vector<vector<int>>(2, vector<int>(m + 1, -1))));
    
           function<int(int, bool, bool, int)> dfs = [&](int pos, bool tightLower, bool tightUpper, int evilMatch) ->int   {
                if(evilMatch == m) return 0;
                if(pos == n) return 1;
                
                if(dp[pos][tightLower][tightUpper][evilMatch] != -1){
                    return dp[pos][tightLower][tightUpper][evilMatch];
                }
    
                long long count = 0;
                char start = tightLower ? s1[pos] : 'a';
                char end = tightUpper ? s2[pos] : 'z';
    
                for(char c = start ; c <= end; c++){
                    bool newTightLower = tightLower && (c == s1[pos]);
                    bool newTightUpper = tightUpper && (c == s2[pos]);
    
                    int newEvilMatch = evilMatch;
                    while(newEvilMatch > 0 && evil[newEvilMatch] != c){
                        newEvilMatch = lps[newEvilMatch - 1];
                    }
    
                    if(evil[newEvilMatch] == c){
                        newEvilMatch++;
                    }
                    count = (count + dfs(pos + 1, newTightLower, newTightUpper, newEvilMatch)) % MOD;
                }
                return dp[pos][tightLower][tightUpper][evilMatch] = count;
            };    
    
            return dfs(0, true, true, 0);
        }
    };