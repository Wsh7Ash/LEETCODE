class Solution {
    public:
        int maximalNetworkRank(int n, vector<vector<int>>& roads) {
            vector<int> degree(n, 0);
            vector<vector<bool>> connected(n, vector<bool>(n, false));
    
            for(auto& road : roads){
                int a = road[0];
                int b = road[1];
                degree[a]++;
                degree[b]++;
                connected[a][b] = true;
                connected[b][a] = true;
            }
            int maxRank = 0;
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    int rank = degree[i] + degree[j];
                    if(connected[i][j]){
                        rank--;
                    }
                    maxRank = max(maxRank, rank);
                }
            }
            return maxRank;
        }
    };