class Solution {
    public:
        int maxNonOverlapping(vector<int>& nums, int target) {
            unordered_set<int> prefixSum;
            prefixSum.insert(0);
    
            int curSum = 0;
            int count = 0;
    
            for(int num : nums){
                curSum += num;
                if(prefixSum.find(curSum - target) != prefixSum.end()){
                    count++;
                    curSum = 0;
                    prefixSum.clear();
                    prefixSum.insert(0);
                }else{
                    prefixSum.insert(curSum);
                }
            }
            return count;
        }
    };