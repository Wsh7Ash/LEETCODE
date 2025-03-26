#include <vector>

class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        // If array length is less than 3, no arithmetic slice possible
        if (nums.size() < 3) {
            return 0;
        }
        
        int count = 0;  // Total count of arithmetic slices
        int curr = 0;   // Current count of slices ending at current position
        
        // Iterate through array starting from third element
        for (int i = 2; i < nums.size(); i++) {
            // Check if current three elements form arithmetic sequence
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                curr += 1;    // New slice found
                count += curr; // Add to total count
            } else {
                curr = 0;     // Reset when sequence breaks
            }
        }
        
        return count;
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    // Test case 1
    std::vector<int> nums1 = {1, 2, 3, 4};
    std::cout << solution.numberOfArithmeticSlices(nums1) << std::endl;  // Output: 3
    
    // Test case 2
    std::vector<int> nums2 = {1};
    std::cout << solution.numberOfArithmeticSlices(nums2) << std::endl;  // Output: 0
    
    return 0;
}
Key differences from the Python version:

Syntax:
Uses C++ syntax with semicolons and type declarations
Takes std::vector<int>& as parameter instead of Python list
Uses size() instead of len()
Structure:
Wrapped in a class Solution (common in competitive programming)
Includes necessary header <vector>
Has a main function for testing
Functionality:
Logic remains identical to Python version
Same O(n) time complexity and O(1) space complexity
Handles all the same cases and constraints
The algorithm works the same way:

Checks for arithmetic sequences by comparing consecutive differences
Maintains curr for current sequence count and count for total
Resets curr when sequence breaks
Returns total number of arithmetic subarrays
The C++ version will correctly handle:

Input arrays of length 1 to 5000
Integer values from -1000 to 1000
All the example cases (like [1,2,3,4] returning 3)