class Solution {
    public:
        int largestIsland(vector<vector<int>>& grid) {
            int n = grid.size();
            int islandId = 2;
            unordered_map<int, int> islandSizes;
    
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 1){
                        int size = dfs(grid, i, j, islandId);
                        islandSizes[islandId] = size;
                        islandId++;
                    }
                }
            }
            int maxSize = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 0){
                        unordered_map<int, int> neiIslands;
                        if(i > 0 && grid[i-1][j] > 1) neiIslands[grid[i-1][j]] = islandSizes[grid[i-1][j]];
                        if(i < n-1 && grid[i+1][j] > 1) neiIslands[grid[i+1][j]] = islandSizes[grid[i+1][j]];
                        if(j > 0 && grid[i][j-1] > 1) neiIslands[grid[i][j-1]] = islandSizes[grid[i][j-1]];
                        if(j < n-1 && grid[i][j+1] > 1) neiIslands[grid[i][j+1]] = islandSizes[grid[i][j+1]];
    
                        int curSize = 1;
                        for(auto& e : neiIslands){
                            curSize += e.second;
                        }maxSize = max(maxSize, curSize);
                    }
                }
            }
            if(maxSize == 0){
                for(auto& e : islandSizes){
                    maxSize = max(maxSize, e.second);
                }
            }
            return maxSize;
        }
    
        int dfs(vector<vector<int>>& grid, int i, int j, int islandId){
            if(i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || grid[i][j] != 1) return 0;
            grid[i][j] = islandId;
            return 1 + dfs(grid, i+1, j, islandId) + dfs(grid, i-1, j, islandId)
                     + dfs(grid, i, j+1, islandId) + dfs(grid, i, j-1, islandId);
        }
    };