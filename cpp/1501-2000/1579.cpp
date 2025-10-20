class UnionFind{
    public:
        vector<int> parent, rank;
        int components;
    
        UnionFind(int n){
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            components = n;
    
            for(int i = 1; i <= n; i++){
                parent[i] = i;
            }
        }
    
        int find(int x){
            if(parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
    
        bool unite(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX == rootY) return false;
            if(rank[rootX] < rank[rootY]) parent[rootX] = rootY;
            else if(rank[rootX] > rank[rootY]) parent[rootY] = rootX;
            else{
                parent[rootY] = rootX;
                rank[rootX]--; 
            }
            components--;
            return true;
        }
    
        bool isFullyConnected(){
            return components == 1;
        }
    
        int getComponents(){
            return components;
        }
    };
    
    class Solution {
    public:
        int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
            sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b){
                return a[0] > b[0];
            });
            UnionFind aliceUF(n), bobUF(n);
            int edgesUsed = 0;
    
            for(auto& edge : edges){
                int type = edge[0];
                int u = edge[1];
                int v = edge[2];
                if(type == 3){
                    bool aliceConnected = aliceUF.unite(u, v);
                    bool bobConnected = bobUF.unite(u, v);
                    if(aliceConnected || bobConnected){
                        edgesUsed++;
                    }
                }
            }
            for(auto& edge : edges){
                int type = edge[0];
                int u = edge[1];
                int v = edge[2];
                if(type == 1){
                    if(aliceUF.unite(u, v)){
                        edgesUsed++;
                    }
                }
                else if(type == 2){
                    if(bobUF.unite(u, v)){
                        edgesUsed++;
                    }
                }
            }
            if(!aliceUF.isFullyConnected() || !bobUF.isFullyConnected()){
                return -1;
            }
            
            return edges.size() - edgesUsed;
        }
    };