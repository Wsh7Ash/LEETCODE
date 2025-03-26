#include <vector>
#include <climits>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        // Use long to handle INT_MIN and INT_MAX cases
        long first = LONG_MIN;  // First maximum
        long second = LONG_MIN; // Second maximum
        long third = LONG_MIN;  // Third maximum
        
        // Iterate through the array once
        for (int num : nums) {
            // Skip if num equals any of existing maximums
            if (num == first || num == second || num == third) {
                continue;
            }
            
            // Update maximums accordingly
            if (num > first) {
                third = second;
                second = first;
                first = num;
            }
            else if (num > second) {
                third = second;
                second = num;
            }
            else if (num > third) {
                third = num;
            }
        }
        
        // If third maximum doesn't exist, return first maximum
        if (third == LONG_MIN) {
            return first;
        }
        
        return third;
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    // Test case 1
    std::vector<int> nums1 = {3, 2, 1};
    std::cout << solution.thirdMax(nums1) << std::endl;  // Output: 1
    
    // Test case 2
    std::vector<int> nums2 = {1, 2};
    std::cout << solution.thirdMax(nums2) << std::endl;  // Output: 2
    
    // Test case 3
    std::vector<int> nums3 = {2, 2, 3, 1};
    std::cout << solution.thirdMax(nums3) << std::endl;  // Output: 1
    
    return 0;
}
Let's break down how this solution works:

Approach:
We maintain three variables to track the top three distinct maximums
We use long instead of int to handle edge cases with INT_MIN
Single pass through the array updates these maximums
Algorithm:
Initialize three variables to LONG_MIN
For each number in array:
Skip if it's equal to any existing maximum (handles duplicates)
If greater than first, shift all down and update
If greater than second, shift second down and update
If greater than third, just update third
Return third if it exists, otherwise return first
Key Features:
Handles duplicates by skipping equal values
Uses LONG_MIN as sentinel value
O(n) time complexity with O(1) space complexity
Example Walkthrough for [2,2,3,1]:
text

Collapse

Wrap

Copy
Initial: first=LONG_MIN, second=LONG_MIN, third=LONG_MIN
num=2:   first=2, second=LONG_MIN, third=LONG_MIN
num=2:   skipped (duplicate)
num=3:   first=3, second=2, third=LONG_MIN
num=1:   first=3, second=2, third=1
Result: 1 (third maximum)
Time Complexity: O(n) where n is the length of the input array
Space Complexity: O(1) as we only use three variables

The solution handles all constraints and cases:

Works for arrays of length 1 to 10^4
Handles integers from -2^31 to 2^31 - 1
Correctly returns maximum when third maximum doesn't exist
Properly handles duplicates by counting them as one value