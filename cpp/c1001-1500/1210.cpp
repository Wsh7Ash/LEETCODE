class Solution {
    public:
        int minimumMoves(vector<vector<int>>& grid) {
            
            int n = grid.size();
    
            queue<tuple<int, int, int>> q;
            q.push({0,0,0});
            unordered_set<string> visited;
            visited.insert("0,0,0");
    
            int moves = 0;
            while(!q.empty()){
                int size = q.size();
                for(int i = 0; i < size; i++){
                    auto [r,c, orient] = q.front();
                    q.pop();
    
                    if(r == n - 1 && c == n - 2 && orient == 0) return moves;
    
                    if(orient == 0){ // H
                        //right
                        if(c+2 < n && grid[r][c+2] == 0){
                            string key = to_string(r) + "," + to_string(c+1) + ",0";
                            if(visited.find(key) == visited.end()){
                                visited.insert(key);
                                q.push({r,c+1, 0});
                            }
                        }
    
                        //down;
                        if(r+1 < n && grid[r+1][c] == 0 && grid[r+1][c+1] == 0){
                            string key = to_string(r+1) + "," + to_string(c) + ",0";
                            if(visited.find(key) == visited.end()){
                                visited.insert(key);
                                q.push({r+1, c, 0});
                            }
                        }
    
                        //clockwise rotation
                        if(r+1 < n && grid[r+1][c] == 0 && grid[r+1][c+1] == 0){
                            string key = to_string(r) + "," + to_string(c) + ",1";
                            if(visited.find(key) == visited.end()){
                                visited.insert(key);
                                q.push({r, c, 1});
                            }
                        }
                    }else{  // V
                        // right
                        if(c+1 < n && grid[r][c+1] == 0 && grid[r+1][c+1] == 0){
                            string key = to_string(r) + "," + to_string(c+1) + ",1";
                            if(visited.find(key) == visited.end()){
                                visited.insert(key);
                                q.push({r, c+1, 1});
                            }
                        }
    
                        //down
                        if(r+2 < n && grid[r+2][c] == 0){
                            string key = to_string(r+1) + "," + to_string(c) + ",1";
                            if(visited.find(key) == visited.end()){
                                visited.insert(key);
                                q.push({r+1, c, 1});
                            }
                        }
    
                        //counter clockwise
                        if(c+1 < n && grid[r][c+1] == 0 && grid[r+1][c+1] == 0){
                            string key = to_string(r) + "," + to_string(c) + ",0";
                            if(visited.find(key) == visited.end()){
                                visited.insert(key);
                                q.push({r, c, 0});
                            }
                        }
                    }
                }
                moves++;
            }
            return -1;
        }
    };