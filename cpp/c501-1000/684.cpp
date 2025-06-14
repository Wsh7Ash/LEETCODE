class Solution {
    public:
        int find(vector<int>& p, int node){
            while(p[node] != node){
                p[node] = p[p[node]];
                node = p[node];
            }
            return node;
        }
        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            int n = edges.size();
            vector<int> p(n+1);
            for(int i = 1; i <= n; i++){
                p[i] = i;
            }
            for(const auto& e:edges){
                int u = e[0];
                int v = e[1];
    
                int ru = find(p, u);
                int rv = find(p, v);
    
                if(ru == rv) return e;
                else p[rv] = ru;
            }
            return {};
        }
    };