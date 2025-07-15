class Solution {
    public:
        int partitionDisjoint(vector<int>& nums) {
            int n = nums.size();
            vector<int> min_right(n);
            min_right[n - 1] = nums[n - 1];
            for(int i = n - 2; i >= 0; i--){
                min_right[i] = min(nums[i], min_right[i+1]);
            }
    
            int max_left = nums[0];
            for(int i = 0; i < n - 1; i++){
                max_left = max(max_left, nums[i]);
                if(max_left <= min_right[i + 1]){
                    return i + 1;
                }
            }
            return n;
        }
    };