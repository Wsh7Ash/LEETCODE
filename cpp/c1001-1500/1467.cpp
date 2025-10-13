class Solution {
    public:
        double getProbability(vector<int>& balls) {
            int total = accumulate(balls.begin(), balls.end(), 0);
            int n = total / 2;
            int k = balls.size();
    
            vector<double> fact(total + 1, 1.0);
            for(int i = 1; i <= total; i++){
                fact[i] = fact[i - 1] * i;
            }
    
            
    
            vector<vector<vector<vector<double>>>> dp(k+1,
             vector<vector<vector<double>>>(n+1,
             vector<vector<double>>(k+1,
              vector<double>(k+1, 0.0))));
    
            dp[0][0][0][0] = 1.0;
    
            for(int i = 0; i < k; i++){
                for(int count1 = 0; count1 <= n; count1++){
                    for(int d1 = 0; d1 <= k; d1++){
                        for(int d2 = 0; d2 <= k; d2++){
                            
                            double ways = dp[i][count1][d1][d2];
                            if(ways == 0) continue;
                            
                            int cur_balls = balls[i];
                            for(int x = 0; x <= cur_balls; x++){
                                int y = cur_balls - x;
                                if(count1 + x > n) continue;
    
                                int nd1 = d1 + (x > 0 ? 1 : 0);
                                int nd2 = d2 + (y > 0 ? 1 : 0);
    
                                double comb = fact[cur_balls] / (fact[x] * fact[y]);
                                dp[i+1][count1+x][nd1][nd2] += ways * comb;
                            }
                        }
                    }
                }
            }
            
            double valid_ways = 0.0;
            for(int d = 0; d <= k; d++){
                valid_ways += dp[k][n][d][d];
            }
            double total_ways = fact[total] / (fact[n] * fact[n]);
            return valid_ways / total_ways;
        }
    };