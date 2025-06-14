class Solution {
    public:
        double knightProbability(int n, int k, int row, int column) {
            vector<pair<int, int>> dirs = {{-2,-1}, {-2, 1}, {-1, -2},{-1,2},
                                            {1,-2}, {1,2},{2,-1}, {2,1}};
            
            vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n, vector<double>(n, 0.0)));
            dp[0][row][column] = 1.0;
    
            for(int m = 1;m <= k; m++){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        for(const auto& dir : dirs){
                            int pi = i - dir.first;
                            int pj = j - dir.second;
                            if(pi >= 0 && pi < n && pj >= 0 && pj < n){
                                dp[m][i][j] += dp[m-1][pi][pj] / 8.0;
                            }
                        }
                    }
                }
            }
            double tp = 0.0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n;j++){
                    tp += dp[k][i][j];
                }
            }
            return tp;
        }
    };