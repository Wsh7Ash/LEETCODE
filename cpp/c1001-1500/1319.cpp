class UnionFind{
    private:
        vector<int> parent, rank;
    public:
        UnionFind(int n){
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; i++){
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
            if(rank[rootX] < rank[rootY]) swap(rootX, rootY);
            parent[rootY] = rootX;
            if(rank[rootX] == rank[rootY]) rank[rootX]++;
            return true;
        }
    
    };
    
    class Solution {
    public:
    
        int makeConnected(int n, vector<vector<int>>& connections) {
            
            if(connections.size() < n - 1) return -1;
    
            UnionFind uf(n);
            int coms = n;
            int exCa = 0;
    
            for(const auto& con : connections){
                int a = con[0], b = con[1];
                if(uf.unite(a, b)){
                    coms--;
                }else{
                    exCa++;
                }
            }
    
            if(exCa >= coms - 1) return coms-1;
            return -1;
        }
    };