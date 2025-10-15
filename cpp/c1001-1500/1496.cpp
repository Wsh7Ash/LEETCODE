class Solution {
    public:
        bool isPathCrossing(string path) {
            auto hash = [](const pair<int, int>& p){
                return p.first * 10001 + p.second;
            };
            unordered_set<pair<int, int>, decltype(hash)> visited(0, hash);
    
            int x = 0, y = 0;
            visited.insert({x, y});
            for(char dir : path){
                switch(dir){
                    case 'N': y++; break;
                    case 'S': y--; break;
                    case 'E': x++; break;
                    case 'W': x--; break;
                }
    
                
                if(visited.count({x, y})){
                    return true;
                }
    
                visited.insert({x, y});
            }
            return false;
        }
    };