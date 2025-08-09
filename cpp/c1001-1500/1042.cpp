class Solution {
    public:
        vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
            vector<vector<int>> adj(n + 1);
            for(const auto& path : paths){
                int u = path[0];
                int v = path[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            vector<int> flowerTypes(n, 0);
    
            for(int garden = 1; garden <= n; ++garden){
                unordered_set<int> usedFlowers;
                for(int nei : adj[garden]){
                    if(flowerTypes[nei - 1] != 0){
                        usedFlowers.insert(flowerTypes[nei - 1]);
                    }
                }
                for(int flower = 1; flower <= 4; ++flower){
                    if(usedFlowers.find(flower) == usedFlowers.end()){
                        flowerTypes[garden - 1] = flower;
                        break;
                    }
                }
            }
    
            return flowerTypes;
        }
    };