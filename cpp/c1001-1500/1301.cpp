class Solution {
    public:
        vector<int> pathsWithMaxScore(vector<string>& board) {
            const int MOD = 1e9 + 7;
            int n = board.size();
    
            vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
    
            dp[n-1][n-1] = {0, 1};
    
            for(int i = n -1; i >= 0; i--){
                for(int j = n-1; j >= 0; j--){
                    if(board[i][j] == 'X' || dp[i][j].first == -1) continue;
    
                    int curSum = dp[i][j].first;
                    int curCount = dp[i][j].second;
    
                    if(i > 0 && board[i-1][j] != 'X'){
                        int cellValue =  (board[i-1][j] == 'E') ? 0 : (board[i-1][j] - '0');
                        updateDP(dp, i-1, j, curSum + cellValue, curCount, MOD);
                    }
    
                    if(j > 0 && board[i][j-1] != 'X'){
                        int cellValue =  (board[i][j-1] == 'E') ? 0 : (board[i][j-1] - '0');
                        updateDP(dp, i, j-1, curSum + cellValue, curCount, MOD);
                    }
    
                    if(i > 0 && j > 0 && board[i-1][j-1] != 'X'){
                        int cellValue =  (board[i-1][j-1] == 'E') ? 0 : (board[i-1][j-1] - '0');
                        updateDP(dp, i-1, j-1, curSum + cellValue, curCount, MOD);
                    }
                }
            }
    
            if(dp[0][0].first == -1) return {0, 0};
            return {dp[0][0].first, dp[0][0].second};
        }
    
    private: 
        void updateDP(vector<vector<pair<int, int>>>& dp, int i, int j, int newSum, int newCount, int MOD){
            if(dp[i][j].first < newSum){
                dp[i][j] = {newSum, newCount};
            }else if(dp[i][j].first == newSum){
                dp[i][j].second = (dp[i][j].second + newCount) % MOD;
            }
        }
    };