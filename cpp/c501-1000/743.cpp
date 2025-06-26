class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for(auto& time : times){
            int u = time[0], v = time[1], w = time[2];
            graph[u].emplace_back(v, w);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.emplace(0, k);

        while(!pq.empty()){
            int curDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(curDist > dist[u]) continue;

            for(auto& edge : graph[u]){
                int v = edge.first;
                int w = edge.second;

                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        } 
        int maxDist = *max_element(dist.begin() + 1, dist.end());
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};