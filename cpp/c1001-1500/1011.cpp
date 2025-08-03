class Solution {
    public:
        int shipWithinDays(vector<int>& weights, int days) {
            int left = *max_element(weights.begin(), weights.end());
            int right = accumulate(weights.begin(), weights.end(), 0);
    
            while(left < right){
                int mid = left + (right - left)/ 2;
                int cur = 0;
                int needed = 1;
                for(int w : weights){
                    if(cur + w > mid){
                        needed++;
                        cur = w;
                    }else{
                        cur += w;
                    }
                }
                if(needed <= days) right = mid;
                else left = mid + 1;
            }
            return left;
        }
    };