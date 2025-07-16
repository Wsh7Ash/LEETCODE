class Solution {
    public:
        int maxSubarraySumCircular(vector<int>& nums) {
            int ts = 0;
            int ms = nums[0];
            int cm = 0;
            int mns = nums[0];
            int cmn = 0;
    
            for(int num : nums){
                ts += num;
                cm = max(num, cm + num);
                ms = max(ms, cm);
                cmn = min(num, cmn + num);
                mns = min(mns, cmn);
            }
            if(ms < 0) return ms;
            return max(ms, ts - mns);
        }
    };