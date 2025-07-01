class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        vector<int> res;

        for(int i = 0; i<n; i++){
            if(dfs(i, graph, color)){
                res.push_back(i);
            }
        }
        return res;
    }

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color){
        if(color[node] > 0) return color[node] == 2;
        color[node] = 1;
        for(int n : graph[node]){
            if(color[n] == 2)continue;
            if(color[n] == 1 || !dfs(n, graph, color)) return false;
        }
        color[node] = 2;
        return true;

    }
};