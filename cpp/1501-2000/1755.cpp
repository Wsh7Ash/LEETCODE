class Solution {
    public:
        int minAbsDifference(vector<int>& nums, int goal) {
            int n = nums.size();
            int mid = n / 2;
            vector<int> leftSums;
            generateSums(nums, 0, mid, leftSums);
            vector<int> rightSums;
            generateSums(nums, mid, n, rightSums);
            sort(rightSums.begin(), rightSums.end());
            int minDiff = INT_MAX;
            for(int leftSum : leftSums){
                int target = goal - leftSum;
                int idx = lower_bound(rightSums.begin(), rightSums.end(), target) - rightSums.begin();
                if(idx < rightSums.size()){
                    minDiff = min(minDiff, abs(leftSum + rightSums[idx] - goal));
                }
                if(idx > 0){
                    minDiff = min(minDiff, abs(leftSum + rightSums[idx - 1] - goal));
                }
            }
            return minDiff;
        }
    
        void generateSums(vector<int>& nums, int start, int end, vector<int>& sums){
            sums.push_back(0);
            for(int i = start; i < end; i++){
                int size = sums.size();
                for(int j = 0; j < size; j++){
                    sums.push_back(sums[j] + nums[i]);
                }
            }
        }
    };