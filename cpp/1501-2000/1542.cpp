class Solution {
    public:
        int longestAwesome(string s) {
            int n = s.length();
            int mask =0;
            vector<int> occ(1024, n);
            occ[0] = -1;
            int maxlen = 0;
    
            for(int i = 0; i < n; i++){
                int digit = s[i] - '0';
                mask ^= (1 << digit);
                if(occ[mask] != n){
                    maxlen = max(maxlen, i - occ[mask]);
                }else{
                    occ[mask] = i;
                }
    
                for(int d = 0; d < 10; d++){
                    int tm = mask ^ (1 << d);
                    if(occ[tm] != n){
                        maxlen = max(maxlen, i - occ[tm]);
                    }
                }
            }
            return maxlen;
        }
    };