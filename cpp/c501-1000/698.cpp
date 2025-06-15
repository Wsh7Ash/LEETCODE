class Solution {
    public:
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            int ts = accumulate(nums.begin(), nums.end(), 0);
            if(ts % k != 0) return false;
            int ta = ts / k;
            sort(nums.begin(), nums.end(), greater<int>());
            vector<bool> used(nums.size(), false);
            return bt(nums, used, 0, k, 0, ta);
        }
        bool bt(vector<int>& nums, vector<bool>& used, int start, int k, int cur_sum, int ta){
            if(k == 1) return true;
            if(cur_sum == ta) return bt(nums, used, 0, k - 1, 0, ta);
            for(int i = start; i < nums.size(); i++){
                if(!used[i] && cur_sum + nums[i] <= ta){
                    used[i] = true;
                    if(bt(nums,used, i + 1, k, cur_sum + nums[i], ta)){
                        return true;
                    }
                    used[i] = false;
                }
            }
            return false;
        }
    }; 