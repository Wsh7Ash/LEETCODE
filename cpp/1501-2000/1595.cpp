class Solution {
    public:
        int connectTwoGroups(vector<vector<int>>& cost) {
            int size1 = cost.size();
            int size2 = cost[0].size();
            
            vector<int> minCost2(size2, INT_MAX);
            for (int j = 0; j < size2; j++) {
                for (int i = 0; i < size1; i++) {
                    minCost2[j] = min(minCost2[j], cost[i][j]);
                }
            }
            
            vector<int> dp(1 << size2, INT_MAX);
            dp[0] = 0;
            
            for (int i = 0; i < size1; i++) {
                vector<int> new_dp(1 << size2, INT_MAX);
                
                for (int mask = 0; mask < (1 << size2); mask++) {
                    if (dp[mask] == INT_MAX) continue;
                    
                    for (int j = 0; j < size2; j++) {
                        int new_mask = mask | (1 << j);
                        new_dp[new_mask] = min(new_dp[new_mask], dp[mask] + cost[i][j]);
                    }
                }
                dp = move(new_dp);
            }
            
            int result = INT_MAX;
            for (int mask = 0; mask < (1 << size2); mask++) {
                if (dp[mask] == INT_MAX) continue;
                
                int total = dp[mask];
                for (int j = 0; j < size2; j++) {
                    if (!(mask & (1 << j))) {
                        total += minCost2[j];
                    }
                }
                result = min(result, total);
            }
            
            return result;
        }
    };