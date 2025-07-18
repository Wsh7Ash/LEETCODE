class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            unordered_map<int, int> prefixSumCount;
            int prefixSum = 0;
            int res = 0;
    
            prefixSumCount[0] = 1;
            for(int num : nums){
                prefixSum += num;
                int target = prefixSum - goal;
                if(prefixSumCount.find(target) != prefixSumCount.end()){
                    res += prefixSumCount[target];
                }
                prefixSumCount[prefixSum]++;
            }
            return res;
        }
    };