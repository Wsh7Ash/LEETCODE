class Solution {
    public:
        double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
            vector<vector<pair<int, double>>> graph(n);
            for(int i = 0; i < edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
                double p = succProb[i];
                graph[u].push_back({v, p});
                graph[v].push_back({u, p});
            }
    
            vector<double> maxP(n, 0.0);
            maxP[start_node] = 1.0;
    
            priority_queue<pair<double, int>> pq;
            pq.push({1.0, start_node});
    
            while(!pq.empty()){
                auto [curP, node] = pq.top();
                pq.pop();
    
                if(curP < maxP[node]) continue;
    
                for(auto [nei, edgeP] : graph[node]){
                    double newP = curP * edgeP;
    
                    if(newP > maxP[nei]){
                        maxP[nei] = newP;
                        pq.push({newP, nei});
                    }
                }
            }
            return maxP[end_node];
        }
    };