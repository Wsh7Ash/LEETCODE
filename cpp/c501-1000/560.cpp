class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> prefixSumCount;
            prefixSumCount[0] = 1;
            int curSum = 0;
            int count = 0;
    
            for (int num : nums){
                curSum += num;
                if(prefixSumCount.find(curSum - k) != prefixSumCount.end()){
                    count += prefixSumCount[curSum - k];
                }
                prefixSumCount[curSum]++;
            }
            return count;
        }
    };