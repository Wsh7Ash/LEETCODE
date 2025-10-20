class Solution {
    public:
        int minCostConnectPoints(vector<vector<int>>& points) {
            int n = points.size();
            if(n == 1) return 0;
    
            vector<tuple<int, int, int>> edges;
    
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    edges.push_back({dist, i, j});
                }
            }
    
            sort(edges.begin(), edges.end());
    
            vector<int> parent(n);
            vector<int> rank(n, 0);
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
    
            auto find = [&](int x){
                while(parent[x] != x){
                    parent[x] = parent[parent[x]];
                    x = parent[x];
                }
                return x;
            };
    
            auto unionSets = [&](int x, int y){
                int rootX = find(x);
                int rootY = find(y);
    
                if(rootX == rootY) return false;
    
                if(rank[rootX] < rank[rootY]) parent[rootX] = rootY;
                else if(rank[rootX] > rank[rootY]) parent[rootY] = rootX;
                else{
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
                return true;
            };
    
            int totalCost = 0;
            int edgesUsed;
    
            for(auto& [weight, u, v] : edges){
                if(unionSets(u, v)){
                    totalCost += weight;
                    edgesUsed++;
                    if(edgesUsed == n - 1) break;
                }
            }
            return totalCost;
    
        }
    };