class Solution {
    public:
        vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
            int n = nums.size();
            vector<int> res(n, 0);
    
            vector<int> prefixSum(n, 0);
            prefixSum[0] = nums[0];
            for(int i = 1; i < n; i++){
                prefixSum[i] = prefixSum[i-1] + nums[i];
            }
            for(int i = 0; i < n; i++){
                int leftSum = 0, rightSum = 0;
                if(i > 0){
                    leftSum = i * nums[i] - prefixSum[i - 1];
                }
                if(i < n - 1){
                    int sumRight = prefixSum[n - 1] - prefixSum[i];
                    rightSum = sumRight - (n - 1 - i) * nums[i]; 
                }
                res[i] = leftSum + rightSum;
            }
            return res;
        }
    };