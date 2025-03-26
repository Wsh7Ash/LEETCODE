#include <vector>
#include <iostream>

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        // dp[i] represents the number of combinations to make sum i
        std::vector<unsigned int> dp(target + 1, 0);
        
        // Base case: empty sum (target = 0) can be made in 1 way (by taking nothing)
        dp[0] = 1;
        
        // For each possible sum from 1 to target
        for (int i = 1; i <= target; i++) {
            // Try each number from nums
            for (int num : nums) {
                // If we can subtract num from current sum i
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
};

// Test code
int main() {
    Solution sol;
    
    // Test case 1
    std::vector<int> nums1 = {1, 2, 3};
    int target1 = 4;
    std::cout << sol.combinationSum4(nums1, target1) << std::endl;  // Should print 7
    
    // Test case 2
    std::vector<int> nums2 = {9};
    int target2 = 3;
    std::cout << sol.combinationSum4(nums2, target2) << std::endl;  // Should print 0
    
    return 0;
}
Let's break down how this solution works:

Approach:
This is a bottom-up dynamic programming solution
Unlike typical combination problems, order matters here (e.g., (1,2) and (2,1) are different)
Think of it as: for each target sum, how many ways can we reach it using the given numbers?
DP Definition:
dp[i]: number of possible combinations that sum up to i
We use unsigned int because the result can be larger than a regular int but fits in 32 bits
Base Case:
dp[0] = 1: there's one way to make sum 0 (by taking no numbers)
All other dp values initialized to 0
Recurrence Relation:
For each sum i from 1 to target
For each number num in nums
If i >= num, then dp[i] += dp[i - num]
This counts all possible ways to make sum i by using each number
Example Walkthrough (nums = [1,2,3], target = 4):
text

Collapse

Wrap

Copy
dp[0] = 1
dp[1] = 1  (using 1)
dp[2] = 2  (dp[1]+1 using 1, dp[0]+1 using 2)
dp[3] = 4  (dp[2]+1 using 1, dp[1]+1 using 2, dp[0]+1 using 3)
dp[4] = 7  (dp[3]+1 using 1, dp[2]+1 using 2, dp[1]+1 using 3)
The 7 combinations for target 4 are:

(1,1,1,1)
(1,1,2)
(1,2,1)
(2,1,1)
(2,2)
(1,3)
(3,1)
Time Complexity: O(target * nums.length)

Outer loop runs target times
Inner loop runs nums.length times
Space Complexity: O(target)

We only need a 1D DP array of size target + 1
Key Points:

This is different from typical combination problems because order matters
We use unsigned int to handle larger numbers within 32-bit constraint
The solution handles all the constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 1000
1 <= target <= 1000
No need to sort the array as we're counting all possible combinations
The solution correctly handles both test cases and meets all the problem constraints. Note that we don't need to generate the actual combinations, just count them, which makes DP an efficient approach.