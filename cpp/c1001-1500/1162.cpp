class Solution {
    public:
        int maxDistance(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
            queue<pair<int, int>> q;
    
            for(int i = 0;i < n; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 1){
                        dist[i][j] = 0;
                        q.push({i, j});
                    }
                }
            }
    
            if(q.empty() || q.size() == n * n) return -1;
    
            vector<pair<int, int>> dirs = {{-1, 0},{0, 1}, {1, 0}, {0, -1}};
            int maxDist = 0;
    
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
    
                for(auto [dx, dy] : dirs){
                    int nx = x + dx;
                    int ny = y + dy;
    
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                        if(dist[nx][ny] > dist[x][y] + 1){
                            dist[nx][ny] = dist[x][y] + 1;
                            maxDist = max(maxDist, dist[nx][ny]);
                            q.push({nx, ny});
                        }
                    }
                }
            }
    
            return maxDist;
        }
    };