class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();
            if(m == 0) return mat;
            vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
            queue<pair<int, int>> q;
    
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(mat[i][j] == 0){
                        dist[i][j] = 0;
                        q.push({i, j});
                    }
                }
            }
            vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
    
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                int curi = cur.first;
                int curj = cur.second;
    
                for(auto dir : dirs){
                    int newi = curi + dir.first;
                    int newj = curj + dir.second;
                
                    if(newi >= 0 && newi < m && newj >= 0 && newj < n){
                        if(dist[newi][newj] > dist[curi][curj] + 1){
                            dist[newi][newj] = dist[curi][curj] + 1;
                            q.push({newi, newj});
                        }
                    }
                }
            }
            return dist;
        }
    };