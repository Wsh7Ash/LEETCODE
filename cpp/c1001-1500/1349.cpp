class Solution {
    public:
        int maxStudents(vector<vector<char>>& seats) {
            int m = seats.size();
            int n = seats[0].size();
    
            vector<int> validRows(m, 0);
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(seats[i][j] == '.'){
                        validRows[i] |= (1 << j);
                    }
                }
            }
    
            vector<vector<int>> dp(m + 1, vector<int>(1 << n, -1));
            dp[0][0] = 0;
    
            for(int i = 1; i <= m; i++){
                int valid = validRows[i-1];
                for(int mask = 0; mask < (1 << n); mask++){
                    if((mask & valid) != mask) continue;
                    if((mask &(mask >> 1)) != 0) continue;
                    for(int prevMask = 0; prevMask < (1 << n); prevMask++){
                        if(dp[i-1][prevMask] == -1) continue;
                        if((mask & (prevMask >> 1)) != 0)continue;
                        if((mask & (prevMask << 1)) != 0)continue;
                        int students = 0;
                        for(int j = 0; j < n; j++){
                            if(mask & ( 1 << j)) students++;
                        }
                        dp[i][mask] = max(dp[i][mask], dp[i-1][prevMask] + students);
                    }
                }
            }
    
            int res = 0;
            for(int mask = 0; mask < ( 1 << n); mask++){
                res = max(res, dp[m][mask] == -1 ? 0 : dp[m][mask]);
            }
            return res;
        }
    
    };