class Solution {
    public:
        vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
            int n = nums.size();
    
            vector<vector<int>> coprimes(51);
            for(int i = 1; i <= 50; i++){
                for(int j = 1; j <= 50; j++){
                    if(__gcd(i, j) == 1){
                        coprimes[i].push_back(j);
                    }
                }
            }
            vector<vector<int>> adj(n);
            for(auto& edge : edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            vector<int> res(n, -1);
            vector<vector<pair<int,int>>> path(51);
            dfs(0, -1, 0, nums, adj, coprimes, path, res);
            return res;
        }
    
        void dfs(int node, int parent, int depth, vector<int>& nums, vector<vector<int>>& adj,
                vector<vector<int>>& coprimes, vector<vector<pair<int, int>>>& path, vector<int>& res){
            
            int maxDepth = -1;
            int closestAncestor = -1;
    
            for(int val : coprimes[nums[node]]){
                if(!path[val].empty()){
                    auto& p = path[val].back();
                    if(p.second > maxDepth){
                        maxDepth = p.second;
                        closestAncestor = p.first;
                    }
                }
            }
            res[node] = closestAncestor;
            path[nums[node]].push_back({node, depth});
    
            for(int child : adj[node]){
                if(child != parent){
                    dfs(child, node, depth + 1, nums, adj, coprimes, path, res);
                }
            }
            path[nums[node]].pop_back();
        }
    };