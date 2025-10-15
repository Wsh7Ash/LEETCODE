class Solution {
    public:
        int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
            deque<pair<int, int>> dq;
            int maxVal = INT_MIN;
    
            for(auto& point : points){
                int xj = point[0];
                int yj = point[1];
    
                while(!dq.empty() && xj - dq.front().second > k){
                    dq.pop_front();
                }
    
                if(!dq.empty()){
                    int curValue = dq.front().first + (yj + xj);
                    maxVal = max(maxVal, curValue);
                }
    
                int curDiff = yj - xj;
                while(!dq.empty() && dq.back().first <= curDiff){
                    dq.pop_back();
                }
                dq.push_back({curDiff, xj});
            }
    
            return maxVal;
        }
    };