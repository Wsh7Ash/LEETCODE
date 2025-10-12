class Solution {
    public:
        int minStartValue(vector<int>& nums) {
            int minPrefixSum = 0;
            int curSum = 0;
    
            for(int num : nums){
                curSum += num;
                minPrefixSum = min(minPrefixSum, curSum);
            }
    
            return max(1, 1 - minPrefixSum);
        }
    };