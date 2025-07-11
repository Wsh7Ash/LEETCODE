class Solution {
    public:
        int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
            vector<vector<pair<int, int>>> adj(n);
            for(const auto& edge : edges){
                int u = edge[0];
                int v = edge[1];
                int cnt = edge[2];
                adj[u].emplace_back(v, cnt +1);
                adj[v].emplace_back(u, cnt +1);
            }
    
            vector<int> dist(n, INT_MAX);
            dist[0] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.emplace(0, 0);
    
            while(!pq.empty()){
                auto [cur_dist, u] = pq.top();
                pq.pop();
                if(cur_dist > dist[u]) continue;
                for(const auto& [v, weight] : adj[u]){
                    if(dist[v] > dist[u] + weight){
                        dist[v] = dist[u] + weight;
                        pq.emplace(dist[v], v);
                    }
                }
            }
            int res = 0;
            for(int i = 0; i < n; i++){
                if(dist[i] <= maxMoves){
                    res++;
                }
            }
    
            for(const auto& edge : edges){
                int u = edge[0];
                int v = edge[1];
                int cnt = edge[2];
                int a = max(maxMoves-dist[u], 0);
                int b = max(maxMoves-dist[v], 0);
                res += min(a+b, cnt);
            }
            return res;
        }
    };