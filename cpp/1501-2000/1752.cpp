class Solution {
    public:
        bool check(vector<int>& nums) {
            int n = nums.size();
            int breakPoints = 0;
            for(int i = 0; i < n - 1; i++){
                if(nums[i] > nums[i + 1]){
                    breakPoints++;
                }
            }
            if(breakPoints == 0){
                return true;
            }
            if(breakPoints > 1){
                return false;
            }
    
            return nums[n - 1] <= nums[0]; 
        }
    };