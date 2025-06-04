class Solution {
    public:
        int findLengthOfLCIS(vector<int>& nums) {
            if(nums.empty()) return 0;
    
            int maxlen = 1;
            int curlen = 1;
    
            for(int i = 1; i < nums.size(); i++){
                if(nums[i] > nums[i - 1]){
                    curlen++;
                    maxlen = max(maxlen, curlen);
                }else{
                    curlen = 1;
                }
            }
            return maxlen;
        }
    };