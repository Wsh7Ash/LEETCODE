class Solution {
    public:
        int dominantIndex(vector<int>& nums) {
            int mi = 0;
            int mn = nums[0];
    
            for(int i = 1; i < nums.size(); i++){
                if(nums[i] > mn){
                    mn = nums[i];
                    mi = i;
                }
            }
    
            for(int n : nums){
                if(n != mn && mn < 2 * n){
                    return -1;
                }
            }
            return mi;
        }
    };