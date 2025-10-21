class Solution {
    public:
        int minSubarray(vector<int>& nums, int p) {
            int n = nums.size();
    
            long long total = 0;
            for(int num : nums){
                total += num;
            }
            int target_rem = total % p;
            if(target_rem == 0){
                return 0;
            }
    
            unordered_map<int, int> prefix_rem;
            prefix_rem[0] = -1;
    
            long long cur_prefix = 0;
            int min_len = n;
    
            for(int i = 0; i < n; i++){
                cur_prefix = (cur_prefix + nums[i]) % p;
                int needed_rem = (cur_prefix - target_rem + p) % p;
                if(prefix_rem.find(needed_rem) != prefix_rem.end()){
                    min_len = min(min_len, i - prefix_rem[needed_rem]);
                }
                prefix_rem[cur_prefix] = i;
            }
            return min_len == n ? -1 : min_len;
        }
    };