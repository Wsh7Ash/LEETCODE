class UnionFind{
    public:
        vector<int> parent, rank;
    
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
    
        void unite(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
    
            if(rootX != rootY){
                if(rank[rootX] < rank[rootY]){
                    swap(rootX, rootY);
                }
                parent[rootY] = rootX;
                if(rank[rootX] == rank[rootY]){
                    rank[rootX]++;
                }
            }
        }
    
    };
    
    class Solution {
    public:
        vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
            sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b){
                return a[2] < b[2];
            });
            vector<int> queryIndices(queries.size());
            for(int i = 0; i < queries.size(); i++){
                queryIndices[i] = i;
            }
            sort(queryIndices.begin(), queryIndices.end(), [&](int a, int b){
                return queries[a][2] < queries[b][2];
            });
            UnionFind uf(n);
            vector<bool> res(queries.size());
            int edgeIndex = 0;
    
            for(int i : queryIndices){
                int p = queries[i][0];
                int q = queries[i][1];
                int limit = queries[i][2];
    
                while(edgeIndex < edgeList.size() && edgeList[edgeIndex][2] < limit){
                    uf.unite(edgeList[edgeIndex][0], edgeList[edgeIndex][1]);
                    edgeIndex++;
                }
                res[i] = (uf.find(p) == uf.find(q));
            }
    
            return res;
        }
    };