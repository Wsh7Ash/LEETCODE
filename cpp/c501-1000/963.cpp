class Solution {
    public:
        double minAreaFreeRect(vector<vector<int>>& points) {
            unordered_set<string> pointSet;
            for(const auto& p : points){
                pointSet.insert(to_string(p[0]) + "," + to_string(p[1]));
            }
    
            double minArea = LONG_MAX;
            int n = points.size();
    
            for(int i = 0; i < n; i++){
                for(int j = i + 1;j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        int x1 = points[i][0], y1 = points[i][1];
                        int x2 = points[j][0], y2 = points[j][1];
                        int x3 = points[k][0], y3 = points[k][1];
    
                        int dx1 = x2 - x1, dy1 = y2 - y1;
                        int dx2 = x3 - x1, dy2 = y3 - y1;
                        if(dx1 * dx2 + dy1 * dy2 != 0) continue;
    
                        int x4 = x2 + x3 - x1;
                        int y4 = y2 + y3 - y1;
                        if(pointSet.count(to_string(x4) + "," + to_string(y4))){
                            double area = sqrt(dx1 * dx1 + dy1 * dy1) * sqrt(dx2 * dx2 + dy2 * dy2);
                            if(area < minArea){
                                minArea = area;
                            }
                        }
                    
                    }
                }
            }
    
            return minArea == LONG_MAX ? 0 : minArea;
        }
    };