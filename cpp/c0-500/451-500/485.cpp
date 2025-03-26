class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int maxCount = 0;
            int curCount = 0;
    
            for(int num : nums){
                if(num == 1){
                    curCount++;
                    maxCount = max(maxCount, curCount);
                }else{
                    curCount = 0; 
                }
            }
            return maxCount;
        }
    };