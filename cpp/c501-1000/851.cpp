class Solution {
    public:
        vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
            int n = quiet.size();
            vector<vector<int>> graph(n);
            for(const auto& edge :  richer){
                graph[edge[1]].push_back(edge[0]);
            }
    
            vector<int> ans(n, -1);
            for(int i = 0; i <  n; i++){
                if(ans[i] == -1){
                    dfs(i, graph, quiet, ans);
                }
            }
            return ans;
        }
    
        int dfs(int node, vector<vector<int>>& graph, vector<int>& quiet, vector<int>& ans){
            if(ans[node] != -1) return ans[node];
            int mq = node;
            for(int nei : graph[node]){
                int can = dfs(nei, graph, quiet, ans);
                if(quiet[can] < quiet[mq]){
                    mq = can;
                }
            }
            ans[node] = mq;
            return mq;
        }
    };