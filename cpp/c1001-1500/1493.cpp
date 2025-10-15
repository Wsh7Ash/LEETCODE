class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int prev = 0;
            int cur = 0;
            int maxLength = 0;
            bool hasZero = false;
    
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 1){
                    cur++;
                }else{
                    hasZero = true;
                    prev = cur;
                    cur = 0;
                }
                maxLength = max(maxLength, prev + cur);
            }
    
            if(!hasZero){
                return nums.size() - 1;
            }
            return maxLength;
        }
    };