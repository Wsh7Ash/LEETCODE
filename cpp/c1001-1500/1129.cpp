class Solution {
    public:
        vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
            vector<vector<pair<int, int>>> graph(n);
            for(auto& edge : redEdges){
                graph[edge[0]].push_back({edge[1], 0});
            }
            for(auto& edge : blueEdges){
                graph[edge[0]].push_back({edge[1], 1});
            }
    
            vector<vector<int>> visited(n, vector<int>(2, 0));
            vector<int> res(n, INT_MAX);
            queue<tuple<int, int, int>> q;
            q.push({0, -1, 0});
            visited[0][0] = 1;
            visited[0][1] = 1;
            res[0] = 0;
    
            while(!q.empty()){
                auto [node, color, steps] = q.front();
                q.pop();
                for(auto& [nei, edgeColor] : graph[node]){
                    if(edgeColor != color && !visited[nei][edgeColor]){
                        visited[nei][edgeColor] = 1;
                        int newSteps = steps + 1;
                        if(newSteps < res[nei]){
                            res[nei] = newSteps;
                        }
                        q.push({nei, edgeColor, newSteps});
                    }
                }
            }
            for(int i = 0; i < n; i++){
                if(res[i] == INT_MAX){
                    res[i] = -1;
                }
            }
            return res;
        }
    };