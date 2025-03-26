#include <vector>
#include <algorithm>

class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        
        // up[i] represents length of longest wiggle sequence ending at i with up wiggle
        // down[i] represents length of longest wiggle sequence ending at i with down wiggle
        std::vector<int> up(n, 1);
        std::vector<int> down(n, 1);
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                // Can extend a down sequence
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            else if (nums[i] < nums[i-1]) {
                // Can extend an up sequence
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            }
            else {
                // If equal, sequences remain same length
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        
        return std::max(up[n-1], down[n-1]);
    }
};

// Here's a space-optimized version using O(1) space:
class SolutionOptimized {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        
        int up = 1;    // length of longest wiggle sequence ending with up
        int down = 1;  // length of longest wiggle sequence ending with down
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                up = down + 1;
            }
            else if (nums[i] < nums[i-1]) {
                down = up + 1;
            }
            // If equal, both remain same, so no update needed
        }
        
        return std::max(up, down);
    }
};

// Test code
#include <iostream>

int main() {
    SolutionOptimized sol;
    
    // Test case 1
    std::vector<int> nums1 = {1,7,4,9,2,5};
    std::cout << sol.wiggleMaxLength(nums1) << std::endl;  // Should print 6
    
    // Test case 2
    std::vector<int> nums2 = {1,17,5,10,13,15,10,5,16,8};
    std::cout << sol.wiggleMaxLength(nums2) << std::endl;  // Should print 7
    
    // Test case 3
    std::vector<int> nums3 = {1,2,3,4,5,6,7,8,9};
    std::cout << sol.wiggleMaxLength(nums3) << std::endl;  // Should print 2
    
    return 0;
}
Key differences from the Python version:

Syntax: Uses C++ syntax with explicit type declarations and semicolons.
Vector: Uses std::vector<int> instead of Python's dynamic arrays.
Namespace: Uses std:: namespace for standard library functions like max.
Two Versions:
First version uses DP arrays similar to the Python solution (O(n) space)
Second optimized version uses just two variables (O(1) space)
Both versions have:

Time Complexity: O(n) where n is the length of nums
Space Complexity:
First version: O(n) for the two DP arrays
Optimized version: O(1) using only two variables
The optimized version is more space-efficient and typically preferred in C++ unless you need the actual sequences (not just their lengths). It works on the same principle but only keeps track of the previous values instead of storing the entire array.

The logic remains identical to the Python version:

For an up wiggle (nums[i] > nums[i-1]), we can extend a down sequence
For a down wiggle (nums[i] < nums[i-1]), we can extend an up sequence
When numbers are equal, sequence lengths don't change
Final answer is the maximum of the up and down sequences
The test cases demonstrate the solution works correctly for all the example inputs provided in the problem statement.