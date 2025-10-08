class Solution {
    public:
        int minCost(vector<vector<int>>& grid) {
            
            int m = grid.size();
            int n = grid[0].size();
    
            vector<vector<int>> dirs = {{0,1}, {0,-1},{1,0},{-1, 0}};
    
            vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    
            deque<pair<int, int>> dq;
    
            dist[0][0] = 0;
            dq.push_front({0, 0});
    
            while(!dq.empty()){
                auto [x, y] = dq.front();
                dq.pop_front();
    
                int curCost = dist[x][y];
    
                for(int dir = 0; dir < 4; dir++){
                    int newX = x + dirs[dir][0];
                    int newY = y + dirs[dir][1];
    
                    if(newX >= 0 && newX < m && newY >= 0 && newY < n){
                        int cost = (grid[x][y] == dir + 1) ? 0 : 1;
                        int newCost = curCost + cost;
    
                        if(newCost < dist[newX][newY]){
                            dist[newX][newY] = newCost;
    
                            if(cost == 0){
                                dq.push_front({newX, newY});
                            }else{
                                dq.push_back({newX, newY});
                            }
                        }
                    }
                }
            }
            return dist[m-1][n-1];
        }
    };