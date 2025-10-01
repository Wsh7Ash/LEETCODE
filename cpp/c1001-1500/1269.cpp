class Solution {
    public:
        int numWays(int steps, int arrLen) {    
            const int MOD = 1e9 + 7;
            
            int maxPos = min(arrLen - 1, steps / 2 + 1);
    
            vector<long long> prev(maxPos + 1, 0);
            vector<long long> cur(maxPos + 1, 0);
    
            prev[0] = 1;
    
            for(int step = 1; step <= steps; step++){
                fill(cur.begin(), cur.end(), 0);
    
                for(int pos = 0; pos <= maxPos; pos++){
                    cur[pos] = prev[pos];
    
                    if(pos > 0){
                        cur[pos] = (cur[pos] + prev[pos - 1]) % MOD;
                    }
    
                    if(pos < maxPos && pos + 1 < arrLen){
                        cur[pos] = (cur[pos] + prev[pos + 1]) % MOD;
                    }
                }
                swap(prev, cur);
            }
            return (int)prev[0];
        }
    };