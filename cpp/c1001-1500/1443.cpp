class Solution {
    public:
        int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
            vector<vector<int>> graph(n);
            for(auto& edge : edges){
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
            return dfs(0, -1, graph, hasApple);
        }
    
    private:
        int dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& hasApple){
            int totalTime = 0;
            for(int child : graph[node]){
                if(child == parent) continue;
                int childTime = dfs(child, node, graph, hasApple);
                if(childTime > 0 || hasApple[child]){
                    totalTime += childTime + 2;
                }
            }
            return totalTime;
        }
    };