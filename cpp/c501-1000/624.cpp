class Solution {
    public:
        int maxDistance(vector<vector<int>>& arrays) {
            if(arrays.empty()) return 0;
            int min_val = arrays[0][0];
            int max_val = arrays[0].back();
            int max_dist = 0;
    
            for(int i = 1; i < arrays.size();i++){
                int cur_first = arrays[i][0];
                int cur_last = arrays[i].back();
    
                max_dist = max(max_dist, abs(cur_first - max_val));
                max_dist = max(max_dist, abs(cur_last - min_val));
    
                min_val = min(min_val, cur_first);
                max_val = max(max_val, cur_last);
            }
            return max_dist;
        }
    };