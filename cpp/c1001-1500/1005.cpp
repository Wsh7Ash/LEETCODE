class Solution {
    public:
        int largestSumAfterKNegations(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            for(int i = 0; i < n && k > 0; i++){
                if(nums[i] < 0){
                    nums[i] = nums[i]*-1;
                    k--;
                }else{break;}
            }
            if(k > 0){
                sort(nums.begin(), nums.end());
                if(k % 2 == 1){
                    nums[0] = nums[0]*-1;
                }
            }
            return accumulate(nums.begin(),  nums.end(), 0);
        }
    };