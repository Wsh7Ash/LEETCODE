class Solution {
    public:
        bool carPooling(vector<vector<int>>& trips, int capacity) {
            int max_loc = 0;
            for(const auto& trip : trips){
                max_loc = max(max_loc, trip[2]);
            }
    
            vector<int> diff(max_loc + 2, 0);
    
            for(const auto& trip : trips){
                int num = trip[0];
                int from = trip[1];
                int to = trip[2];
                diff[from] += num;
                diff[to] -= num;
            }
    
            int cur_pas = 0;
            for(int i = 0; i <= max_loc; i++){
                cur_pas += diff[i];
                if(cur_pas > capacity){
                    return false;
                } 
            }
    
            return true;
        }
    };