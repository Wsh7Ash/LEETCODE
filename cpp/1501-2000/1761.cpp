class Solution {
    public:
        int minTrioDegree(int n, vector<vector<int>>& edges) {
            vector<vector<bool>> adjMatrix(n + 1, vector<bool>(n + 1, false));
            vector<vector<int>> adjList(n + 1);
            vector<int> degree(n + 1, 0);
    
            for(const auto& edge : edges){
                int u = edge[0];
                int v = edge[1];
                adjMatrix[u][v] = true;
                adjMatrix[v][u] = true;
                adjList[u].push_back(v);
                adjList[v].push_back(u);
                degree[u]++;
                degree[v]++;
            }
    
            int minDegree = INT_MAX;
    
            for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                    if(!adjMatrix[i][j])continue;
                    for(int k = j + 1; k <= n; k++){
                        if(adjMatrix[i][k] && adjMatrix[j][k]){
                            int trioDegree = (degree[i] - 2) + (degree[j] - 2) + (degree[k] - 2);
                            minDegree = min(minDegree, trioDegree);
                        }
                    }
                }
            }
            return (minDegree == INT_MAX) ? -1 : minDegree;
        }
    };