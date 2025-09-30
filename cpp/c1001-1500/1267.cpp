class Solution {
    public:
        int countServers(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
    
            vector<int> rc(m, 0);
            vector<int> cc(n, 0);
            vector<pair<int, int>> servers;
    
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 1){
                        rc[i]++;
                        cc[j]++;
                        servers.push_back({i, j});
                    }
                }
            }
    
            int res = 0;
            for(auto [row, col] : servers){
                if(rc[row] > 1 || cc[col] > 1){
                    res++;
                }
            }
            return res;
        }
    };