class Solution {
    public:
        int countRestrictedPaths(int n, vector<vector<int>>& edges) {
            const int MOD = 1e9 + 7;
    
            std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
            for(auto& edge : edges){
                int u = edge[0], v = edge[1], w = edge[2];
                graph[u].push_back({v, w});
                graph[v].push_back({u, w});
            }
    
            std::vector<long long> dist(n + 1, LLONG_MAX);
            dist[n] = 0;
            std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>
                ,std::greater<std::pair<long long, int>>> pq;
            pq.push({0, n});
    
            while(!pq.empty()){
                auto [curDist, u] = pq.top();
                pq.pop();
                if(curDist > dist[u]) continue;
                for(auto& [v, w] : graph[u]){
                    if(dist[u] + w < dist[v]){
                        dist[v] = dist[u] + w;
                        pq.push({dist[v] , v});
                    }
                }
            }
            
            std::vector<int> nodes(n);
            for(int i = 1; i <= n; i++){
                nodes[i - 1] = i;
            }
            std::sort(nodes.begin(), nodes.end(), [&](int a, int b){
                return dist[a] > dist[b];
            });
    
            std::vector<int> pathCount(n + 1, 0);
            pathCount[1] = 1;
            for(int node : nodes){
                if(pathCount[node] == 0) continue;
                for(auto& [nei, weight] : graph[node]){
                    if(dist[node] > dist[nei]){
                        pathCount[nei] = (pathCount[nei] + pathCount[node]) % MOD;
                    }
                }
            }
            return pathCount[n];
        }
    };