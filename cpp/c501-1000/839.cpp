class UnionFind{
    public:
        vector<int> parent;
        vector<int> rank;
    
        UnionFind(int size){
            parent.resize(size);
            rank.resize(size, 0);
            for(int i = 0; i < size; i++){
                parent[i] = i;
            }
        }
    
        int find(int x){
            if(parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
    
        void unionSets(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY){
                if(rank[rootX] > rank[rootY]){
                    parent[rootY] = rootX;
                }else if(rank[rootX] <  rank[rootY]){
                    parent[rootX] = rootY;
                }else{
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
    };
    class Solution {
    public:
        int numSimilarGroups(vector<string>& strs) {
            int n = strs.size();
            UnionFind uf(n);
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if(isSimilar(strs[i], strs[j])){
                        uf.unionSets(i, j);
                    }
                }
            }
            unordered_map<int, int> groups;
            for(int i = 0; i <  n; i++){
                groups[uf.find(i)]++;
            }
            return groups.size();
        }
    
        bool isSimilar(const string& a, const string& b){
            int diff = 0;
            for(int i = 0; i < a.size(); i++){
                if(a[i] != b[i]){
                    diff++;
                    if(diff > 2){
                        return false;
                    }
                }
            }
            return diff == 0 || diff == 2;
        }
    
    
    };
    
    