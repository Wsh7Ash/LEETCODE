class Solution {
    public:
        int smallestRangeI(vector<int>& nums, int k) {
            if(nums.size() == 1) return 0;
            int min_num = *min_element(nums.begin(), nums.end());
            int max_num = *max_element(nums.begin(), nums.end());
            int diff = max_num - min_num - 2 * k;
            return diff > 0 ? diff : 0;
        }
    };