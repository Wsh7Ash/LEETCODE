class Solution {
    public:
        int findUnsortedSubarray(vector<int>& nums) {
            int n = nums.size();
            if(n <= 1) return 0;
    
            int l = 0, r = n - 1;
            while(l < n-1 && nums[l] <= nums[l+1]) l++;
            if(l == n-1) return 0;
            while(r > 0 && nums[r] >= nums[r-1]) r--;
    
            int min_val = INT_MAX;
            int max_val = INT_MIN;
            for(int i = l; i <= r; i++){
                min_val = min(min_val, nums[i]);
                max_val = max(max_val, nums[i]);
            }
            while(l >0 && nums[l-1] > min_val) l--;
            while(r < n-1 && nums[r+1] < max_val) r++;
            return r - l +1;
        }
    };