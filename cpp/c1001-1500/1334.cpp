class Solution {
    public:
        int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            
            const int INF = INT_MAX / 2;
            vector<vector<int>> dist(n, vector<int>(n, INF));
    
            for(int i = 0; i < n; i++){
                dist[i][i] = 0;
            }
    
            for(const auto& edge : edges){
                int from = edge[0];
                int to = edge[1];
                int weight = edge[2];
                dist[from][to] = weight;
                dist[to][from] = weight;
            }
    
            for(int k = 0; k < n; k++){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]){
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
    
            int minNei = n;
            int resCity = -1;
    
            for(int i = 0; i < n; i++){
                int neiCount = 0;
                for(int j = 0; j < n; j++){
                    if(i != j && dist[i][j] <= distanceThreshold){
                        neiCount++;
                    }
                }
    
                if(neiCount < minNei || (neiCount == minNei && i > resCity)){
                    minNei = neiCount;
                    resCity = i;
                }
            }
            return resCity;
        }
    };