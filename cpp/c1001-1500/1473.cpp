class Solution {
    public:
        int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
            const int INF = 1e9;
            vector<vector<int>> dp(n + 1, vector<int>(target + 1, INF));
            if(houses[0] == 0){
                for(int color = 1; color <= n; color++){
                    dp[color][1] = cost[0][color - 1];
                }
            }else{
                dp[houses[0]][1] = 0;
            }
    
            for(int i = 1; i < m; i++){
                vector<vector<int>> newDp(n + 1, vector<int>(target + 1, INF));
                for(int prevColor = 1; prevColor <= n; prevColor++){
                    for(int neiHoods = 1; neiHoods <= target; neiHoods++){
                        if(dp[prevColor][neiHoods] == INF) continue;
                        if(houses[i] == 0){
                            for(int curColor = 1; curColor <= n; curColor++){
                                int newNeiHoods = neiHoods + (curColor != prevColor);
                                if(newNeiHoods > target) continue;
                                int newCost = dp[prevColor][neiHoods] + cost[i][curColor - 1];
                                newDp[curColor][newNeiHoods] = min(newDp[curColor][newNeiHoods], newCost);
                            }
                        }else{
                            int curColor = houses[i];
                            int newNeiHoods = neiHoods + (curColor != prevColor);
                            if(newNeiHoods > target) continue;
                            newDp[curColor][newNeiHoods] = min(newDp[curColor][newNeiHoods], dp[prevColor][neiHoods]);
    
                        }
                    }
                }
                dp = move(newDp);
            }
            int res = INF;
            for(int color = 1; color <= n; color++){
                res = min(res, dp[color][target]);
            }
            return res == INF ? -1 : res;
        }
    };