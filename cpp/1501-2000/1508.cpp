class Solution {
    public:
        int rangeSum(vector<int>& nums, int n, int left, int right) {
            const int MOD = 1e9+7;
    
            vector<int> subArraySums;
            for(int i = 0; i < n; i++){
                int sum = 0;
                for(int j = i; j < n; j++){
                    sum += nums[j];
                    subArraySums.push_back(sum);
                }
            }
    
            sort(subArraySums.begin(), subArraySums.end());
            
            long long res = 0;
            for(int i = left - 1; i <= right - 1; i++){
                res = (res + subArraySums[i]) % MOD;
            }
    
            return res;
        }
    };