+class Solution {
    public:
        int getMaxLen(vector<int>& nums) {
            int n = nums.size();
            int maxlen = 0;
            int pos = 0;
            int neg = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] == 0){
                    pos = 0;
                    neg = 0;
                }else if(nums[i] > 0){
                    pos++;
                    neg = (neg > 0) ? neg + 1 : 0;
                }else{
                    int temp = pos;
                    pos = (neg > 0 ) ? neg + 1 : 0;
                    neg = temp + 1;
                }
                maxlen = max(maxlen, pos);
            }
            return maxlen;
        }
    };