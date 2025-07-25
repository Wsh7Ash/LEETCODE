class UnionFind{
    public:
        unordered_map<int, int> parent;
        int count = 0;
    
        int find(int x){
            if(parent.find(x) == parent.end()){
                parent[x] = x;
                count++;
            }
            if(parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
    
        void unite(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY){
                parent[rootX] = rootY;
                count--;
            }
        }
    
        int getCount(){
            return count;
        }
    };
    
    class Solution {
    public:
        int removeStones(vector<vector<int>>& stones) {
            UnionFind uf;
            for(const auto& stone : stones){
                int row = stone[0];
                int col = stone[1] + 10001;
                uf.unite(row, col);
            }
            return stones.size() - uf.getCount();
        }
    };