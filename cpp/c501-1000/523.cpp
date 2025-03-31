class Solution {
    public:
        bool checkSubarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> remainder_map;
            remainder_map[0] = -1;
            int prefixSum = 0;
    
            for(int i = 0; i < nums.size(); i++){
                prefixSum += nums[i];
                int remainder = prefixSum % k;
                if(remainder_map.find(remainder) != remainder_map.end()){
                    if(i - remainder_map[remainder] >= 2){
                        return true;
                    }
                }else{
                    remainder_map[remainder] = i;
                }
            }
            return false;
        }
    };