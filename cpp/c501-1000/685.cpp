class Solution {
    public:
        vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
            int n = edges.size();
            vector<int> p(n + 1);
            vector<int> c1, c2;
            
            for(auto& e : edges){
                int u = e[0];
                int v = e[1];
                if(p[v] == 0)   p[v] = u;
                else{
                    c1 = {p[v], v};
                    c2 = e;
                    e[1] = 0;
                    break;
                }
            }
            vector<int> root(n + 1, 0);
            for(int i = 1; i <= n; i++){
                root[i] = i;
            }
            for(auto& e : edges){
                int u = e[0];
                int v = e[1];
                int ru = find(root, u);
                int rv = find(root, v);
                if(ru == rv){
                    if(c1.empty()){
                        return e;
                    }else{
                        return c1;
                    }
                }
                root[rv] = ru;
            }
            return c2;
        }
        int find(vector<int>& root, int node){
            while(root[node] != node){
                root[node] = root[root[node]];
                node = root[node];
            }
            return node;
        }
    };