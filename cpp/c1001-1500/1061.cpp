class UnionFind{
    public:
        vector<int> parent;
        UnionFind(int size){
            parent.resize(size);
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
    
        void UnionSet(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY){
                if(rootX < rootY){
                    parent[rootY] = rootX;
                }else{
                    parent[rootX] = rootY;
                }
            }
        }
    };
    
    class Solution {
    public:
        string smallestEquivalentString(string s1, string s2, string baseStr) {
            UnionFind uf(26);
            for(int i = 0; i < s1.size(); ++i){
                int a = s1[i] - 'a';
                int b = s2[i] - 'a';
                uf.UnionSet(a, b);
            }      
            string res;
            for(char c : baseStr){
                int root = uf.find(c - 'a');
                res += 'a' + root;
            }
            return res;
        }
    };