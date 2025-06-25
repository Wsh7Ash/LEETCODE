class Solution {
    public:
        int cherryPickup(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
            return max(0, dp(grid, memo, 0, 0, 0));
        }
    
        int dp(vector<vector<int>>& grid, vector<vector<vector<int>>>& memo, int x1, int y1, int x2){
            int y2 = x1 + y1 - x2;
            int n = grid.size();
    
            if(x1 >= n || y1 >= n || x2 >= n || y2 >= n || grid[x1][y1] == -1 || grid[x2][y2] == -1) return -1;
            if(memo[x1][y1][x2] != INT_MIN){
                return memo[x1][y1][x2];
            }        
            if(x1 == n - 1 && y1 == n - 1) return grid[x1][y1];
    
            int res = max(max(dp(grid, memo, x1+ 1, y1, x2+1), dp(grid, memo, x1+1, y1, x2)),
                        max(dp(grid, memo, x1, y1 + 1, x2+1), dp(grid, memo, x1, y1 + 1, x2)));
            if(res < 0){
                memo[x1][y1][x2] = -1;
                return -1;
            }
            res += grid[x1][y1];
            if(x1 != x2 || y1 != y2){
                res += grid[x2][y2];
            }
    
            memo[x1][y1][x2] = res;
            return res;
        }
    };