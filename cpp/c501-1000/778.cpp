class Solution {
    public:
        int swimInWater(vector<vector<int>>& grid) {
            int n = grid.size();
            int l = grid[0][0];
            int r = 0;
            for(const auto& row : grid){
                for(int v : row){
                    r = max(r, v);
                }
            }
            while(l < r){
                int m = l + (r - l) / 2;
                if(canReach(grid, m)){
                    r = m;
                }else{
                    l = m + 1;
                }
            }
            return l;
        }
    
        bool canReach(const vector<vector<int>>& grid, int t){
            int n = grid.size();
            if(grid[0][0] > t || grid[n-1][n-1] > t){
                return false;
            }
    
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.push({0,0});
            visited[0][0] = true;
    
            int dirs[4][2] = {{-1,0}, {1,0}, {0, -1}, {0,1}};
    
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                int i = cur.first;
                int j = cur.second;
    
                if(i == n - 1 && j == n - 1){
                    return true;
                }
    
                for(const auto& dir : dirs){
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < n && !visited[ni][nj] && grid[ni][nj] <= t){
                        visited[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
            return false;
        }
    };