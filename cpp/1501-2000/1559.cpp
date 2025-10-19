class Solution {
    public:
        bool containsCycle(vector<vector<char>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<bool>> visited(m, vector<bool>(n, false));
    
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(!visited[i][j]){
                        if(dfs(grid, visited, i, j, -1, -1, grid[i][j])){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
    
    private:
        bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int p1, int p2, char t){
            int m = grid.size();
            int n = grid[0].size();
            if(visited[i][j]) return true;
            visited[i][j] = true;
            vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
            for(auto& dir : dirs){
                int ni = i + dir[0];
                int nj = j + dir[1];
                if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == t){
                    if(ni == p1 && nj == p2){
                        continue;
                    }
                    if(dfs(grid, visited, ni, nj, i, j, t)){
                        return true;
                    }
                }
            }
            return false;
        }
    };