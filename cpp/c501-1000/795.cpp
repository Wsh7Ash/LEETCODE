class Solution {
    public:
        int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
            int res = 0;
            int s = -1;
            int pc = 0;
    
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] > right){
                    s = i;
                    pc = 0;
                }else if(nums[i] >= left){
                    pc = i - s;
                    res += pc;
                }else res += pc;
            }
            return res;
        }
    };