class Solution {
    public:
        vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);
            for(auto& edge : edges){
                int u = edge[0] - 1;
                int v = edge[1] - 1;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            vector<int> res(n - 1, 0);
    
            for(int mask = 1; mask < (1 << n); mask++){
                if(__builtin_popcount(mask) <= 1) continue;
                int start = -1;
                for(int i = 0; i < n; i++){
                    if(mask & (1 << i)){
                        start = i;
                        break;
                    }
                }
    
                auto [node1, dist1] = bfs(start, mask, adj);
                auto [node2, diameter] = bfs(node1, mask, adj);
    
                int reached = 0;
                vector<bool> visited(n, false);
                queue<int> q;
                q.push(start);
                visited[start] = true;
    
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    reached++;
                    for(int v : adj[u]){
                        if((mask & (1 << v)) && !visited[v]){
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
                if(reached == __builtin_popcount(mask) && diameter > 0){
                    res[diameter - 1]++;
                }
            }
            return res;
        }
    
    private:
        pair<int, int> bfs(int start, int mask, vector<vector<int>>& adj){
            int n = adj.size();
            queue<int> q;
            vector<int> dist(n, -1);
            q.push(start);
            dist[start] = 0;
            int farthest = start;
            int maxDist = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(dist[u] > maxDist){
                    maxDist = dist[u];
                    farthest = u;
                }
                for(int v : adj[u]){
                    if((mask & (1 << v)) && dist[v] == -1){
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            return {farthest, maxDist};
        }
    };