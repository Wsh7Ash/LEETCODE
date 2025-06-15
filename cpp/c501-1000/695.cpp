class Solution {
    public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int ma = 0;
            int m = grid.size();
            if(m == 0) return 0;
            int n = grid[0].size();
    
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 1){
                        int area = dfs(grid, i, j, m, n);
                        ma = max(ma, area);
                    }
                }
            }
            return ma;
        }
         int dfs(vector<vector<int>>& grid, int i, int j, int m, int n){
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;
            grid[i][j] = 0;
            return 1 
            + dfs(grid, i + 1, j, m, n) 
            + dfs(grid, i - 1, j, m, n) 
            + dfs(grid, i, j + 1, m, n) 
            + dfs(grid, i, j - 1, m, n);
         }
    };