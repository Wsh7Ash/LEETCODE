class UnionFind{
    private:
        vector<int> parent;
    public:
        UnionFind(int size){
            parent.resize(size);
            for(int i = 0; i < size; i++)parent[i] = i;
        }
    
        int find(int x){
            if(parent[x] != x)parent[x] = find(parent[x]);
            return parent[x];
        }
    
        void unite(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY)parent[rootX] = rootY;
        }
    };
    
    class Solution {
    public:
        int regionsBySlashes(vector<string>& grid) {
            int n = grid.size();
            UnionFind uf(4 * n * n);
    
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    int index = 4 * (i * n + j);
                    char c = grid[i][j];
    
                    if(c == '/'){
                        uf.unite(index, index + 3);
                        uf.unite(index + 1, index + 2);
                    }else if(c == '\\'){
                        uf.unite(index, index + 1);
                        uf.unite(index + 2, index + 3);
                    }else{
                        uf.unite(index, index + 1);
                        uf.unite(index + 1, index + 2);
                        uf.unite(index + 2, index + 3);
                    }
                    if(j + 1 < n){
                        uf.unite(index + 1, 4 * (i * n + j + 1) + 3);
                    }
                    if(i + 1 < n){
                        uf.unite(index + 2, 4 * ((i + 1) * n + j));
                    }
                }
            }
    
            int res = 0;
            for(int i = 0; i < 4 * n * n; i++){
                if(uf.find(i) == i){
                    res++;
                }
            }
            return res;
        }
    };