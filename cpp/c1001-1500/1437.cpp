class Solution {
    public:
        bool kLengthApart(vector<int>& nums, int k) {
            int lastOnePos = -1;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 1){
                    if(lastOnePos != -1 && (i - lastOnePos - 1) < k){
                        return false;
                    }
                    lastOnePos = i;
                }
            }
            return true;
        }
    };