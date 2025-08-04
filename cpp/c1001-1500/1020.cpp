class Solution {
    public:
        int numEnclaves(vector<vector<int>>& grid) {
            int m = grid.size();
            if(m == 0) return 0;
            int n = grid[0].size();
            queue<pair<int, int>> q;
    
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if((i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1){
                        grid[i][j] = -1;
                        q.push({i, j});
                    }
                }
            }
    
            vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                for(auto dir : dirs){
                    int x = cur.first + dir.first;
                    int y = cur.second + dir.second;
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                        grid[x][y] = -1;
                        q.push({x, y});
                    }
                }
            }
    
            int c = 0;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 1)
                        c++;
                }
            }
            return c;
        }
    };