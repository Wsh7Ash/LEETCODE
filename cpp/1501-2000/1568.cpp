class Solution {
    public:
        int minDays(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
    
            int landCount = 0;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    landCount += grid[i][j];
                }
            }
            int islands = countIslands(grid);
            if(islands != 1) return 0;
            if(landCount == 1) return 1;
            if(landCount == 2) return 2;
            if(hasArticulationPoint(grid)){
                return 1;
            }
            return 2;
        }
    
    private:
        int countIslands(vector<vector<int>>& grid){
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            int count = 0;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 1 && !visited[i][j]){
                        count ++;
                        dfs(grid, visited, i, j);
                    }
                }
            }
            return count;
        }
    
        void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
            int m = grid.size();
            int n = grid[0].size();
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j]) return;
            visited[i][j] = true;
            dfs(grid, visited, i + 1, j);
            dfs(grid, visited, i - 1, j);
            dfs(grid, visited, i, j + 1);
            dfs(grid, visited, i, j - 1);
        }
    
        bool hasArticulationPoint(vector<vector<int>>& grid){
            int m = grid.size();
            int n = grid[0].size();
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;
                        int islands = countIslands(grid);
                        grid[i][j] = 1;
                        if(islands != 1) return true;
                    }
                }
            }
            return false;
        }
    };