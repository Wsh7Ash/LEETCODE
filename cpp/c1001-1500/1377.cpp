class Solution {
    public:
        double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
            vector<vector<int>> graph(n + 1);
            for(auto& edge : edges){
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
    
            return dfs(1, -1, t, target, graph, 1.0);
        }
    
    private:
        double dfs(int cur, int parent, int timeLeft, int target, vector<vector<int>>& graph, double prob){
            if(timeLeft == 0){
                return cur == target ? prob : 0.0;
            }
    
            int childCount = 0;
            for(int nei : graph[cur]){
                if(nei  != parent){
                    childCount++;
                }
            }
    
            if(childCount == 0){
                return cur == target ? prob : 0.0;
            }
    
            for(int nei : graph[cur]){
                if(nei != parent){
                    double res = dfs(nei, cur, timeLeft - 1, target, graph, prob / childCount);
                    if(res > 0) return res;
                }
            }
            return 0.0;
        }
    };