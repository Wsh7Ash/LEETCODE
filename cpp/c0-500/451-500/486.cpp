class Solution {
    public:
        int maxScoreDiff(vector<int>& nums, int left, int right, vector<vector<int>>& dp){
            if(left == right){
                return nums[left];
            }
            if(dp[left][right] != INT_MIN){
                return dp[left][right];
            }
    
            int chooseLeft = nums[left] - maxScoreDiff(nums, left + 1, right, dp);
            int chooseRight = nums[right] - maxScoreDiff(nums, left, right - 1, dp);
    
            dp[left][right] = max(chooseLeft, chooseRight);
            return dp[left][right];
        }
    
        bool predictTheWinner(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
    
            int total = 0;
            for(int num : nums){
                total += num;
            }
            int p1ScoreDiff = maxScoreDiff(nums, 0, n-1, dp);
            return p1ScoreDiff >= 0;
        }
    };