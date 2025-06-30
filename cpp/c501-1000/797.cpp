class Solution {
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<vector<int>> res;
            vector<int> p;
            dfs(graph, 0, p, res);
            return res;
        }
    
        void dfs(vector<vector<int>>& graph, int i, vector<int>& p, vector<vector<int>>& res){
            p.push_back(i);
            if(i == graph.size() - 1){
                res.push_back(p);
            }else{
                for(int n : graph[i]){
                    dfs(graph, n, p, res);
                }
            }
            p.pop_back();
        }
    };