class Solution {
    public:
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            return atMostK(nums, k) - atMostK(nums, k -1);
        }
    private:
        int atMostK(vector<int>& nums, int k){
            int n = nums.size();
            unordered_map<int, int> freq;
            int left = 0;
            int res = 0;
    
            for(int right = 0; right < n; right++){
                if(freq[nums[right]] == 0)k--;
                freq[nums[right]]++;
    
                while(k < 0){
                    freq[nums[left]]--;
                    if(freq[nums[left]] == 0){
                        k++;
                    }
                    left++;
                }
                res += right - left + 1;
            }
            return res;
        }
    };