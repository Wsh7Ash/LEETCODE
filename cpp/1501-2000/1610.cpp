#include <vector>
#include <cmath>
#include <algorithm>
#include <numbers>


class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        std::vector<double> angles;
        int same = 0;
        for(auto& p : points){
            int dx = p[0] - location[0];
            int dy = p[1] - location[1];
            if(dx == 0 && dy == 0){
                same++;
                continue;
            }
            double theta = atan2(dy, dx) * (180 / M_PI);
            angles.push_back(std::fmod(theta + 360, 360));
        }        
        std::sort(angles.begin(), angles.end());
        int n = angles.size();
        for(int i = 0; i < n; i++){
            angles.push_back(angles[i] + 360);
        }

        int maxCount = 0;
        // int left = 0;

        for(int right = 0, left = 0; left < angles.size(); left++){
            while(right < angles.size() && angles[right] - angles[left] <= angle + 1e-9){
                right++;
            }
            maxCount = max(maxCount, right - left);
        }
        return maxCount + same;
    }
};