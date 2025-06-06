class Solution {
    public:
        bool checkPossibility(vector<int>& nums) {
            int v = 0;
            for(int i = 0; i < nums.size() - 1; i++){
                if(nums[i] > nums[i + 1]){
                    if(v == 1){
                        return false;
                    }
                    v++;
                    if(i == 0 || nums[i - 1] <= nums[i + 1]){
                        nums[i] = nums[i + 1];
                    }else{
                        nums[i + 1] = nums[i];
                    }
                }
            }
            return true;
        }
    };