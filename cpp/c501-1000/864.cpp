class Solution {
    public:
        int shortestPathAllKeys(vector<string>& grid) {
            int m = grid.size();
            if(m == 0) return -1;
            int n = grid[0].size();
    
            int start_x = -1, start_y = -1;
            int total_keys = 0;
    
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == '@'){
                        start_x = i;
                        start_y = j;
                    }else if(islower(grid[i][j])){
                        total_keys++;
                    }
                }
            }
    
            int target_mask = (1 << total_keys) - 1;
            queue<tuple<int, int, int>> q;
            q.push({start_x, start_y, 0});
    
            unordered_set<string> visited;
            visited.insert(to_string(start_x) + "," + to_string(start_y) + ",0");
    
            int steps = 0;
            int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
            while(!q.empty()){
                int size = q.size();
                for(int i = 0; i < size; i++){
                    auto [x, y, mask] = q.front();
                    q.pop();
    
                    if(mask == target_mask){
                        return steps;
                    }
    
                    for(auto& dir : dirs){
                        int nx = x + dir[0];
                        int ny = y + dir[1];
                        int new_mask = mask;
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#')continue;
                        char c = grid[nx][ny];
                        if(isupper(c)){
                            int key_needed = c - 'A';
                            if(!(mask & (1 << key_needed)))continue;
                        }else if(islower(c)){
                            int key = c - 'a';
                            new_mask |= (1 << key);
                        }
    
                        string state = to_string(nx) + "," + to_string(ny) + "," + to_string(new_mask);
                        if(visited.find(state) == visited.end()){
                            visited.insert(state);
                            q.push({nx, ny, new_mask});
                        }
                    }
                }
                steps++;
            }
            return -1;
        }
    };