class Solution {
    public:
        int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
            vector<int> prereq(n, 0);
            for(auto& rel : relations){
                int prev = rel[0] - 1;
                int next = rel[1] - 1;
                prereq[next] |= (1 << prev);
            }
    
            vector<int> dp(1 << n, n+1);
            dp[0] = 0;
    
            for(int mask = 0; mask < (1 << n); mask++){
                if(dp[mask] == n + 1) continue;
    
                int available = 0;
                for(int i = 0; i < n; i++){
                    if(!(mask & (1 << i)) & ((prereq[i] & mask) == prereq[i])){
                        available |= (1 << i);
                    }
                }
    
                for(int subset = available; subset > 0; subset = (subset - 1) & available){
                    if(__builtin_popcount(subset) <= k){
                        dp[mask | subset] = min(dp[mask | subset], dp[mask] + 1);
                    }
                }
            }
    
            return dp[(1 << n) - 1]; 
        }
    };