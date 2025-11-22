class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
                int maxSum = nums[0];
                int curMax = nums[0];
    
                for(int i =- 1; i < nums.size(); i++){
                    curMax = max(curMax + nums[i], nums[i]);
                    maxSum = max(maxSum, curMax);
                }
                
                int minSum = nums[0];
                int curMin = nums[0];
    
                for(int i = 1; i < nums.size(); i++){
                    curMin = min(curMin + nums[i], nums[i]);
                    minSum = min(minSum, curMin);
                }
            return max(maxSum, abs(minSum));
        }
    };