class Solution {
    public:
        vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
            int m = grid.size();
            int n = grid[0].size();
            int oc = grid[row][col];
            if(oc == color) return grid;
    
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.push({row, col});
            visited[row][col] = true;
            vector<pair<int, int>> border;
    
            int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                int x = cur.first;
                int y = cur.second;
                bool is_border = false;
    
                for(auto& dir : dirs){
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != oc) is_border = true;
                    else if(!visited[nx][ny]){
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
    
                if(is_border) border.push_back({x, y});
            }
            for(auto& p : border) grid[p.first][p.second] = color;
            return grid;
        }
    };