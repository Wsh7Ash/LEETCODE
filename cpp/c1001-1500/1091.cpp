class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
    
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            queue<tuple<int, int, int>> q;
            q.push({0,0,1});
            visited[0][0] = true;
    
            int dirs[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1}, {-1,1},{-1,-1}};
    
            while(!q.empty()){
                auto[r,c,dist] = q.front();
                q.pop();
    
    
                if(r == n -1 && c == n - 1){
                    return dist;
                }
    
                for(auto& dir : dirs){
                    int nr = r + dir[0];
                    int nc = c + dir[1];
    
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && !visited[nr][nc]){
                        visited[nr][nc] = true;
                        q.push({nr, nc, dist+1});
                    } 
                }
            }
            return -1;
        }
    };