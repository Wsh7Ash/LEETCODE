class Solution {
    public:
        int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
            vector<vector<int>> grid(n, vector<int>(n, 1));
            for(const auto& mine :  mines){
                grid[mine[0]][mine[1]] = 0;
            }
    
            vector<vector<int>> l(n, vector<int>(n, 0));
            vector<vector<int>> r(n, vector<int>(n, 0));
            vector<vector<int>> u(n, vector<int>(n, 0));
            vector<vector<int>> d(n, vector<int>(n, 0));
    
            for(int i = 0; i < n; i++){
                for(int j = 0;j < n; j++){
                    if(grid[i][j] == 1){
                        l[i][j] = (j == 0) ? 1 : l[i][j-1] + 1;
                        u[i][j] = (i == 0) ? 1 : u[i-1][j] + 1;
                    }else{
                        l[i][j] = 0;
                        u[i][j] = 0;
                    }
                }
            }
            for(int i = n-1; i >= 0; i--){
                for(int j = n-1; j >= 0; j--){
                    if(grid[i][j] == 1){
                        r[i][j] = (j == n-1) ? 1 : r[i][j+1]+ 1;
                        d[i][j] = (i == n-1) ? 1 : d[i+1][j]+ 1;
                    }else{
                        r[i][j] = 0;
                        d[i][j] = 0;
                    }
                }
            }
            int mo = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j <  n; j++){
                    int o = min({l[i][j], r[i][j], u[i][j], d[i][j]});
                    mo = max(mo, o);
                }
            }
            return mo;
        }
    };