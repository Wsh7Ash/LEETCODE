class Solution {
    public:
        int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
            vector<int> partner(n);
            for(auto& pair : pairs){
                partner[pair[0]] = pair[1];
                partner[pair[1]] = pair[0];
            }
    
            vector<vector<int>> rank(n, vector<int>(n));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n - 1; j++){
                    rank[i][preferences[i][j]] = j;
                }
            }
            int unhappyCount = 0;
            for(int x = 0; x < n; x++){
                int y = partner[x];
                for(int u : preferences[x]){
                    if(u == y) break;
                    int v = partner[u];
                    if(rank[u][x] < rank[u][v]){
                        unhappyCount++;
                        break;
                    }
                }
            }
            return unhappyCount;
        }
    };