class Solution {
    public:
        int specialArray(vector<int>& nums) {
           int n = nums.size();
           sort(nums.begin(), nums.end(), greater<int>());
           for(int x = 0; x <= n; x++){
            int count = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] >= x){
                    count++;
                }else{
                    break;
                }
            }
            if(count == x){
                return x;
            }
           } 
           return -1;
        }
    };