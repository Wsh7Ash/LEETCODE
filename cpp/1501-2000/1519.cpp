class Solution {
    public:
        vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
            vector<vector<int>> graph(n);
            for(auto& edge : edges){
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }   
            vector<int> res(n, 0);
            vector<bool> visited(n, false);
            dfs(0, graph, labels, visited, res);
            return res;
        }
    
    private: 
    
        vector<int> dfs(int node, vector<vector<int>>& graph, string& labels, vector<bool>& visited, vector<int>& res){
            visited[node] = true;
            vector<int> count(26, 0);
            count[labels[node] - 'a']++;
            for(int nei : graph[node]){
                if(!visited[nei]){
                    vector<int> childCount = dfs(nei, graph, labels, visited, res);
                    for(int i = 0; i < 26; i++){
                        count[i] += childCount[i];
                    }
                }
            }
            res[node] = count[labels[node] - 'a'];
            return count;
        }
    };