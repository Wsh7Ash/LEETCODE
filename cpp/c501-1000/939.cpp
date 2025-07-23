class Solution {
    public:
        int minAreaRect(vector<vector<int>>& points) {
            unordered_set<int> pointSet;
            for(const auto& point : points){
                pointSet.insert(point[0] * 40001 + point[1]);
            }
    
            int minArea = INT_MAX;
            int n = points.size();
            for(int i = 0; i < n; i++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                for(int j = i + 1; j < n; j++){
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    if(x1 != x2 && y1 != y2){
                        if(pointSet.count(x1 * 40001 + y2) && pointSet.count(x2 * 40001 + y1)){
                            int area = abs(x2 - x1) * abs(y2 - y1);
                            if(area < minArea){
                                minArea = area;
                            }
                        }
                    }
                }
            }
            return minArea == INT_MAX ? 0 : minArea;
        }
    };