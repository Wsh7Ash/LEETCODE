class Solution {
    public:
        vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
            vector<vector<int>> graph(n);
            for(const auto& edge : edges){
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
            vector<int> count(n, 1);
            vector<int> res(n, 0);
    
            function<void(int, int)> postOrder = [&](int node, int parent){
                for(int nei : graph[node]){
                    if(nei != parent){
                        postOrder(nei, node);
                        count[node] += count[nei];
                        res[node] += res[nei] + count[nei];
                    }
                }
            };
            function<void(int, int)> preOrder = [&](int node, int parent){
                for(int nei : graph[node]){
                    if(nei != parent){
                        res[nei] = res[node] - count[nei] + (n - count[nei]);
                        preOrder(nei, node);
                    }
                }
            };
    
            postOrder(0, -1);
            preOrder(0, -1);
    
            return res;
        }
    };