+class Solution {
    public:
        vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
            vector<int> parent(n + 1);
            iota(parent.begin(), parent.end(), 0);
            function<int(int)> find = [&](int x){
                if(parent[x] != x){
                    parent[x] = find(parent[x]);
                }
                return parent[x];
            };
            auto unite = [&](int x, int y){
                int rootX = find(x);
                int rootY = find(y);
                if(rootX != rootY){
                    parent[rootY] = rootX;
                }
            };
    
            for(int i = threshold + 1; i <= n; i++){
                for(int j = i * 2; j <= n; j+=i){
                    unite(i, j);
                }
            }
            vector<bool> res;
            for(auto& q : queries){
                res.push_back(find(q[0]) == find(q[1]));
            }
            return res;
        }
    };