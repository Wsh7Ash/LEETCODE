class Solution {
    public:
        int waysToMakeFair(vector<int>& nums) {
            int n = nums.size();
            int leftEven = 0, leftOdd = 0;
            int rightEven = 0, rightOdd = 0;
    
            for(int i = 0; i < n; i++){
                if(i % 2 == 0){
                    rightEven += nums[i];
                }else{
                    rightOdd += nums[i];
                }
            }
            int count = 0;
            for(int i = 0; i < n; i++){
                if(i % 2 == 0){
                    rightEven -= nums[i];
                }else{
                    rightOdd -= nums[i];
                }
                if(leftEven + rightOdd == leftOdd + rightEven){
                    count++;
                }
                if(i % 2 == 0) leftEven += nums[i];
                else leftOdd += nums[i];
            }
            return count;
        }
    };