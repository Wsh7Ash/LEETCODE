class Solution {
    public:
        vector<int> minSubsequence(vector<int>& nums) {
            
            sort(nums.rbegin(), nums.rend());
            int totalSum = accumulate(nums.begin(), nums.end(), 0);
            int subsequenceSum = 0;
            vector<int> res;
    
            for(int i = 0; i < nums.size(); i++){
                subsequenceSum += nums[i];
                res.push_back(nums[i]);
    
                if(subsequenceSum > totalSum - subsequenceSum) break;
            }
    
            return res;
        }
    };