class DSU{

    public:
        vector<int> parent;
        vector<int> size;
    
        DSU(int n){
            parent.resize(n);
            size.resize(n, 1);
            for(int i = 0; i < n; i++) parent[i] = i;
        }
    
        int find(int x){
            if(parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
    
        void unite(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY){
                if(size[rootX] < size[rootY]) swap(rootX, rootY);
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    };
    class Solution {
    public:
        int largestComponentSize(vector<int>& nums) {
            int max_num = *max_element(nums.begin(), nums.end());
            DSU dsu(max_num + 1);
    
            for(int num : nums){
                for(int factor = 2; factor * factor <= num; factor++){
                    if(num % factor == 0){
                        dsu.unite(num, factor);
                        dsu.unite(num, num / factor);
                    }
                }
            }      
    
            unordered_map<int, int> root_counts;
            int max_size = 0;
            for(int num : nums){
                int root = dsu.find(num);
                root_counts[root]++;
                max_size = max(max_size, root_counts[root]);
            }
            return max_size;
        }
    };