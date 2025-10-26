class Solution {
    public:
        int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
            if(m < n) swap(m, n);
            int max_mask = pow(3, n);
            vector<int> intro_count(max_mask, 0), extro_count(max_mask, 0);
            vector<int> row_happiness(max_mask, 0);
            vector<vector<int>> cost(3, vector<int>(3, 0));
            cost[1][1] = -60, cost[1][2] = -10;
            cost[2][1] = -10, cost[2][2] = 40;
            for(int mask = 0; mask < max_mask; mask++){
                int happiness = 0;
                for(int i = 0; i < n; i++){
                    int type = (mask / (int)pow(3, i)) % 3;
                    if(type == 1){
                        intro_count[mask]++;
                        happiness += 120;
                    }else if(type == 2){
                        extro_count[mask]++;
                        happiness += 40;
                    }
                    if(i > 0){
                        int left_type = (mask / (int)pow(3, i - 1)) % 3;
                        if(type != 0 && left_type != 0){
                            happiness += cost[type][left_type];
                        }
                    }
                }
                row_happiness[mask] = happiness;
            }
            vector<vector<vector<vector<int>>>> dp(m + 1,
                                                    vector<vector<vector<int>>>(max_mask,
                                                    vector<vector<int>>(introvertsCount + 1,
                                                    vector<int>(extrovertsCount + 1, -1))));
            return dfs(0, 0, introvertsCount, extrovertsCount, m, n, max_mask, intro_count, extro_count, row_happiness, cost, dp);
        }
    
    private:
        int dfs(int row, int prev_mask, int intro, int extro, int m, int n, int max_mask,
                vector<int>& intro_count, vector<int>& extro_count, vector<int>& row_happiness,
                vector<vector<int>>& cost, vector<vector<vector<vector<int>>>>& dp){
            
            if(row == m) return 0;
            if(dp[row][prev_mask][intro][extro] != -1){
                return dp[row][prev_mask][intro][extro];
            }
            int res = 0;
            for(int mask = 0; mask < max_mask; mask++){
                if(intro_count[mask] > intro || extro_count[mask] > extro){
                    continue;
                }
                int happiness = row_happiness[mask];
                for(int i = 0; i < n; i++){
                    int cur_type = (mask / (int)pow(3, i)) % 3;
                    int prev_type = (prev_mask / (int)pow(3, i)) % 3;
                    if(cur_type != 0 && prev_type != 0){
                        happiness += cost[cur_type][prev_type];
                    }
                }
                res = max(res, happiness + dfs(row+1, mask, intro - intro_count[mask], extro - extro_count[mask],
                        m, n, max_mask, intro_count, extro_count, row_happiness, cost, dp));
            }
            return dp[row][prev_mask][intro][extro] = res;
        }
    };