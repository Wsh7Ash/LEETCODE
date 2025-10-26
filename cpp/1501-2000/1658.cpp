class Solution {
    public:
        int minOperations(vector<int>& nums, int x) {
            int total = accumulate(nums.begin(), nums.end(), 0);
            int target = total - x;
            if(target < 0) return -1;
            if(target == 0) return nums.size();
            int left = 0, cur = 0, max_len = -1;
            for(int right = 0; right < nums.size(); right++){
                cur += nums[right];
                while(cur > target && left <= right){
                    cur -= nums[left++];
                }
                if(cur == target){
                    max_len = max(max_len, right - left + 1);
                }
            }
            return max_len == -1 ? -1 : nums.size() - max_len;
        }
    };