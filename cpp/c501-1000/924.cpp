class UnionFind{
    public:
        vector<int> parent;
        vector<int> size;
    
        UnionFind(int n){
            parent.resize(n);
            size.resize(n, 1);
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
    
        void unite(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY){
                if(size[rootX] < size[rootY]){
                    swap(rootX, rootY);
                }
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    };
    
    class Solution {
    public:
        int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
            int n = graph.size();
            UnionFind uf(n);
    
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if(graph[i][j] == 1){
                        uf.unite(i, j);
                    }
                }
            }      
    
            unordered_map<int, int> infectedCount;
            for(int node : initial){
                int root = uf.find(node);
                infectedCount[root]++;
            }
    
            int maxSize = -1;
            int res = -1;
            sort(initial.begin(), initial.end());
    
            for(int node : initial){
                int root = uf.find(node);
                if(infectedCount[root] == 1){
                    if(uf.size[root] > maxSize){
                        maxSize = uf.size[root];
                        res = node;
                    }else if(uf.size[root] == maxSize && node < res){
                        res = node;
                    }
                }
            }
            if(res == -1) return initial[0];
            else return res;
        }
    };