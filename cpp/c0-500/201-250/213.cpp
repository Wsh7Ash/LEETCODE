class Solution {
    private:
        // Helper function to solve standard House Robber problem (non-circular)
        int robLinear(vector<int>& nums, int start, int end) {
            int prev = 0;    // Money from robbing previous house
            int curr = 0;    // Maximum money up to current house
            
            for (int i = start; i <= end; i++) {
                int temp = curr;
                // Either rob current house (add prev) or skip it (keep curr)
                curr = max(prev + nums[i], curr);
                prev = temp;
            }
            
            return curr;
        }
        
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            
            // Base cases
            if (n == 1) return nums[0];
            if (n == 2) return max(nums[0], nums[1]);
            
            // Case 1: Rob houses 0 to n-2 (exclude last house)
            int robFirst = robLinear(nums, 0, n-2);
            
            // Case 2: Rob houses 1 to n-1 (exclude first house)
            int robLast = robLinear(nums, 1, n-1);
            
            // Return maximum of the two cases
            return max(robFirst, robLast);
        }
    };