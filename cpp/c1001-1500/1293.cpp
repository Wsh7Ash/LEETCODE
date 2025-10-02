class Solution {
    public:
        int shortestPath(vector<vector<int>>& grid, int k) {
            int m = grid.size();
            int n = grid[0].size();
    
            if(k >= m + n - 2){
                return m + n - 2;
            }
    
            queue<vector<int>> q;
            vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
    
            vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
            q.push({0, 0, 0});
            visited[0][0][0] = true;
    
            int steps = 0;
    
            while(!q.empty()){
                int size = q.size();
    
                for(int i = 0; i < size; i++){
                    vector<int> cur = q.front();
                    q.pop();
    
                    int row = cur[0];
                    int col = cur[1];
                    int obs = cur[2];
                    if(row == m -1 && col == n - 1){
                        return steps;
                    }
    
                    for(const auto& dir : dirs){
                        int newRow = row +dir[0];
                        int newCol = col +dir[1];
    
                        if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n){
                            int newObs = obs + grid[newRow][newCol];
    
                            if(newObs <= k && !visited[newRow][newCol][newObs]){
                                visited[newRow][newCol][newObs] = true;
                                q.push({newRow, newCol, newObs});
                            }
                        }
                    }
                }
                steps++;
            }
    
            return -1;
        }
    };