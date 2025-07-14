class Solution {
    public:
        int smallestRangeII(vector<int>& nums, int k) {
            int n = nums.size();
            if(n==1) return 0;
    
            sort(nums.begin(), nums.end());
            int min_s = nums[n - 1] - nums[0];
            for(int i = 0; i < n - 1; i++){
                int cmax = max(nums[i] + k, nums[n-1] -k);
                int cmin = min(nums[0] + k, nums[i+1] -k);
                min_s = min(min_s, cmax - cmin);
            }
            return min_s;
        }
    };