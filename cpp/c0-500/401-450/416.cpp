#include <vector>

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        // Calculate total sum
        for (int num : nums) {
            sum += num;
        }
        
        // If sum is odd, cannot be partitioned into equal subsets
        if (sum % 2 != 0) {
            return false;
        }
        
        int target = sum / 2;
        int n = nums.size();
        
        // Create DP table: dp[i][j] represents if sum j is possible with first i elements
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        
        // Empty subset can make sum 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                // Don't include current number
                dp[i][j] = dp[i-1][j];
                
                // Include current number if possible
                if (j >= nums[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];
                }
            }
        }
        
        return dp[n][target];
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 5, 11, 5};
    cout << boolalpha << solution.canPartition(nums1) << endl;  // Output: true
    
    // Test case 2
    vector<int> nums2 = {1, 2, 3, 5};
    cout << solution.canPartition(nums2) << endl;              // Output: false
    
    return 0;
}
Let's break down how this solution works:

Approach:
This is a variation of the subset sum problem
If we can find a subset with sum equal to half of total sum, then the remaining elements will also sum to half
Use 2D dynamic programming to solve
Algorithm:
Calculate total sum
If sum is odd, return false (impossible to partition equally)
Target becomes sum/2
dp[i][j] represents if sum j is possible using first i elements
For each number, we can either include it or exclude it
Key Features:
Base case: sum 0 is always possible with empty subset
For each position and sum:
Can achieve sum without current number (dp[i-1][j])
Can achieve sum with current number if remaining sum was possible (dp[i-1][j-nums[i-1]])
Time Complexity: O(n * target) where n is array length and target is sum/2
Space Complexity: O(n * target) for DP table
Example Walkthrough for [1,5,11,5]:
text

Collapse

Wrap

Copy
Sum = 22, Target = 11
dp[1][11] -> Check with 1
dp[2][11] -> Check with 1,5
dp[3][11] -> Check with 1,5,11 -> true (11 works)
dp[4][11] -> Check with 1,5,11,5 -> true (5+5+1=11)
Result: true
This solution handles all constraints:

Works for array lengths 1 to 200
Handles numbers from 1 to 100
Correctly identifies if equal partition is possible
The solution can be optimized to use 1D DP to reduce space complexity to O(target), but this 2D version is more readable and easier to understand.