class Solution {
    public:
        int findSpecialInteger(vector<int>& arr) {
            int n = arr.size();
            vector<int> candidates = {arr[n/4], arr[n/2], arr[3*n/4]};
    
            for(int candidate : candidates){
                auto lower = lower_bound(arr.begin(), arr.end(), candidate);
                auto upper = upper_bound(arr.begin(), arr.end(), candidate);
                if(upper - lower > n / 4){
                    return candidate;
                }
            }
            return arr[0];
        }
    };