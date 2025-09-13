class Solution {
    public:
        int getMaximumGold(vector<vector<int>>& grid) {
           int m = grid.size();
           int n = grid[0].size();
           int maxGold = 0;
    
           vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
           function<int(int, int)> dfs = [&](int i, int j) -> int {
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
                return 0;
            }
    
            int curGold = grid[i][j];
            grid[i][j] = 0;
    
            int maxPath = 0;
            for(auto& dir : dirs){
                int ni = i + dir.first;
                int nj = j + dir.second;
                maxPath = max(maxPath, dfs(ni, nj));
            }
    
            grid[i][j] = curGold;
            return curGold + maxPath;
           };
    
            for(int i= 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] != 0){
                        maxGold = max(maxGold, dfs(i, j));
                    }
                }
            }
            return maxGold;
        }
    };