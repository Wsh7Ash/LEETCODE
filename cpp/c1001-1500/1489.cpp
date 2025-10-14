class UnionFind{
    private:
        vector<int> parent, rank;
        int count;
    
    public:
        UnionFind(int n){
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
            count = n;
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
            if(rank[rootX] < rank[rootY]){
                parent[rootX] = rootY;
            }else if(rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
            }else{
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
            return true;
        }
    
        bool connected(){
            return count == 1;
        }
    };
    
    class Solution {
    public:
        vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
            int m = edges.size();
            for(int i = 0; i < m; i++){
                edges[i].push_back(i);
            }
            sort(edges.begin(), edges.end(), [](auto& a, auto& b){
                return a[2] < b[2];
            });
            auto [originalWeight, mstEdges] = findMST(n, edges);
            vector<int> critical, pseudoCritical;
            for(int i = 0; i < m; i++){
                int idx = edges[i][3];
                int weightWithout = findMSTWeight(n, edges, i, -1);
                if(weightWithout > originalWeight){
                    critical.push_back(idx);
                    continue;
                }
                int weightWith = findMSTWeight(n, edges, -1, i);
                if(weightWith == originalWeight){
                    pseudoCritical.push_back(idx);
                }
            }
            return {critical, pseudoCritical};
        }
    
    private:
    
        pair<int, unordered_set<int>> findMST(int n, vector<vector<int>>& edges){
            UnionFind uf(n);
            int totalWeight = 0;
            unordered_set<int> mstEdges;
    
            for(int i = 0; i < edges.size(); i++){
                int u = edges[i][0], v = edges[i][1], w = edges[i][2];
                if(uf.unite(u, v)){
                    totalWeight += w;
                    mstEdges.insert(edges[i][3]);
                }
            }
            return {totalWeight, mstEdges};
        }
    
        int findMSTWeight(int n, vector<vector<int>>& edges, int exclude, int include){
            UnionFind uf(n);
            int totalWeight = 0;
            int edgesUsed = 0;
            if(include != -1){
                int u = edges[include][0], v = edges[include][1], w = edges[include][2];
                if(uf.unite(u, v)){
                    totalWeight += w;
                    edgesUsed++;
                }
            }
            for(int i = 0; i < edges.size(); i++){
                if(i == exclude || i == include) continue;
                int u = edges[i][0], v = edges[i][1], w = edges[i][2];
                if(uf.unite(u, v)){
                    totalWeight += w;
                    edgesUsed++;
                }
            }
            return edgesUsed == n - 1 ? totalWeight : INT_MAX;
        }
    };