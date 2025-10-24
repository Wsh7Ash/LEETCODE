class Solution {
    public:
        vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
            int maxX = 0;
            int maxY = 0;
    
            for(auto& tower : towers){
                maxX = max(maxX, tower[0]);
                maxY = max(maxY, tower[1]);
            }
    
            int maxQuality = -1;
            vector<int> res = {0, 0};
    
            for(int x = 0; x <= maxX + radius; x++){
                for(int y = 0; y <= maxY + radius; y++){
                    int quality = 0;
                    for(auto& tower : towers){
                        int xi = tower[0];
                        int yi = tower[1];
                        int qi = tower[2];
                        double d = sqrt((x - xi) * (x - xi) + (y - yi) * (y - yi));
                        if(d <= radius){
                            quality += floor(qi / (1 + d));
                        }
                    }
                    if(quality > maxQuality){
                        maxQuality = quality;
                        res = {x, y};
                    }else if(quality == maxQuality){
                        if(x < res[0] || (x == res[0] && y < res[1])){
                            res = {x, y};
                        }
                    }
                }
            }
    
            return res;
        }
    };