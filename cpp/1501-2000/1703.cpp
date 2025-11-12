class Solution {
    public:
        int minMoves(vector<int>& nums, int k) {
            vector<int> ones;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 1){
                    ones.push_back(i);
                }
            }
            if(k == 1) return 0;
            vector<int> transformed;
            for(int i = 0; i < ones.size(); i++){
                transformed.push_back(ones[i] - i);;
            }
            vector<long long> prefixSum(transformed.size() + 1, 0);
            for(int i = 0; i < transformed.size(); i++){
                prefixSum[i + 1] = prefixSum[i] + transformed[i];
            }
    
            long long minMoves = LLONG_MAX;
            for(int i = 0; i <= (int)transformed.size() - k; i++){
                int mid = i + k / 2;
                long long leftSum = prefixSum[mid] - prefixSum[i];
                long long rightSum = prefixSum[i + k] - prefixSum[mid + 1];
                long long moves = (long long)transformed[mid] * (mid - i) - leftSum + rightSum - 
                                    (long long)transformed[mid] * (i + k - 1 - mid);
                minMoves = min(minMoves, moves);
            }
            return (int)minMoves;
        }
    };