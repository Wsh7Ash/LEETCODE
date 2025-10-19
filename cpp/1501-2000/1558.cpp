class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int addOps = 0;
            int maxMulOps = 0;
    
            for(int num : nums){
                int mulOps = 0;
                while(num > 0){
                    addOps += (num & 1);
                    mulOps++;
                    num >>= 1;
                }
                maxMulOps = max(maxMulOps, mulOps);
            }
            return addOps + max(0, maxMulOps - 1);
        }
    };