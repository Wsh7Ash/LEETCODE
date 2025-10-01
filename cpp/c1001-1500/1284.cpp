class Solution {
    private:
        int matrixToInt(vector<vector<int>>& mat){
            int res = 0;
            int m = mat.size();
            int n = mat[0].size();
    
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(mat[i][j] == 1){
                        res |= (1 << (i * n + j));
                    }
                }
            }
            return res;
        }
    
    public:
        int minFlips(vector<vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();
    
            int start = matrixToInt(mat);
            if(start == 0) return 0;
    
            queue<pair<int, int>> q;
            unordered_set<int> visited;
    
            q.push({start, 0});
            visited.insert(start);
    
            vector<pair<int, int>> dirs = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
            while(!q.empty()){
                auto [state, steps] = q.front();
                q.pop();
    
                for(int i = 0; i < m; i++){
                   for(int j = 0; j < n; j++){
                        int newState = state;
    
                        for(auto [di, dj] : dirs){
                            int ni = i + di;
                            int nj = j + dj;
                            if(ni >= 0 && ni < m && nj >= 0 && nj < n){
                                int pos = ni * n + nj;
                                newState ^= (1 << pos); 
                            }
                        }   
    
                        if(newState == 0) return steps + 1;
    
                        if(visited.find(newState) == visited.end()){
                            visited.insert(newState);
                            q.push({newState, steps + 1});
                        }
                    }
                }
            }
            return -1;
        }
    };