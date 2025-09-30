class Solution {
    public:
        int closedIsland(vector<vector<int>>& grid) {
            if(grid.empty() || grid[0].empty()) return 0;
    
            int m = grid.size();
            int n = grid[0].size();
    
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 0){
                        dfs(grid, i, j);
                    }
                }
            }
    
            int closedCount = 0;
            for(int i = 0; i < m ;i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 0){
                        dfs(grid, i, j);
                        closedCount++;
                    }
                }
            }
            return closedCount;
        }
    private:
        void dfs(vector<vector<int>>& grid, int i, int j){
            int m = grid.size();
            int n = grid[0].size();
    
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 0) return;
    
            grid[i][j] = 1;
    
            dfs(grid, i + 1, j); 
            dfs(grid, i - 1, j); 
            dfs(grid, i, j + 1); 
            dfs(grid, i, j - 1); 
        }
    };