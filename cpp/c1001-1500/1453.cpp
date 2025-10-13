class Solution {
    public:
        int numPoints(vector<vector<int>>& darts, int r) {
            int n = darts.size();
            int maxPoints = 1;
    
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i == j){
                        int count = 0;
                        for(int k = 0; k < n; k++){
                            double dist = sqrt(pow(darts[i][0] - darts[k][0], 2) + 
                                               pow(darts[i][1] - darts[k][1], 2));
    
                            if(dist <= r + 1e-9){
                                count++;
                            }
                        }
    
                        maxPoints = max(maxPoints, count);
                    }else{
                        int x1 = darts[i][0], y1 = darts[i][1];
                        int x2 = darts[j][0], y2 = darts[j][1];
    
                        double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    
                        if(d > 2 * r + 1e-9) continue;
    
                        double mx = (x1 + x2) / 2.0;
                        double my = (y1 + y2) / 2.0;
    
                        double h = sqrt(r * r - (d / 2) * (d / 2));
    
                        double dx = (y2 - y1) / d;
                        double dy = (x1 - x2) / d;
    
                        vector<pair<double, double>> centers = {
                            {mx + h * dx, my + h * dy},
                            {mx - h * dx, my - h * dy}
                        };
    
                        for(auto& center : centers){
                            int count = 0;
                            for(int k = 0; k < n; k++){
                                double dist = sqrt(pow(center.first - darts[k][0], 2) + pow(center.second - darts[k][1], 2));
                                if(dist <= r + 1e-9) count++;
    
                            }
                            maxPoints = max(maxPoints, count);
                        }
                    }
                }
            }
            return maxPoints;
        }
    };