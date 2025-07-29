
class UnionFind{
    public:
        UnionFind(){
            parent.resize(26);
            for(int i = 0; i < 26; i++){
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
                parent[rootX] = rootY;
            }
        }
    private:
        vector<int> parent;
    };
    
    class Solution {
    public:
        bool equationsPossible(vector<string>& equations) {
            UnionFind uf;
    
            for(const string& eq : equations){
                if(eq[1] == '='){
                    int x = eq[0] - 'a';
                    int y = eq[3] - 'a';
                    uf.unionSets(x, y);
                }
            }
    
            for(const string& eq : equations){
                if(eq[1] == '!'){
                    int x = eq[0] - 'a';
                    int y = eq[3] - 'a';
                    if(uf.find(x) == uf.find(y)){
                        return false;
                    }
                }
            }
            return true;
        }
    };