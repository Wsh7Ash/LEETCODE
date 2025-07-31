class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int m = grid.size();
            if(m == 0) return -1;
            int n = grid[0].size();
    
            queue<pair<int, int>> q;
            int fresh = 0;
    
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 2){
                        q.push({i, j});
                    }else if(grid[i][j] == 1){
                        fresh++;
                    }
                }
            }
    
            if(fresh == 0) return 0;
    
            int mins = -1;
            vector<pair<int, int>> dirs = {{-1,0}, {1,0},{0, -1}, {0, 1}};
    
            while(!q.empty()){
                int size = q.size();
                mins++;
    
                for(int i = 0; i < size; i++){
                    auto cur = q.front();
                    q.pop();
                    int x = cur.first;
                    int y = cur.second;
                
                    for(auto dir : dirs){
                        int nx = x + dir.first;
                        int ny = y + dir.second;
    
                        if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                            grid[nx][ny] = 2;
                            fresh--;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            return fresh == 0 ? mins : -1;
        }
    };