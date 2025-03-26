#include <vector>
#include <string>

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
        
        int start = nums[0];  // Start of current range
        
        for (int i = 1; i <= nums.size(); i++) {
            // Check if current number breaks the sequence
            if (i == nums.size() || nums[i] != nums[i-1] + 1) {
                // If start and end are same, just add single number
                if (start == nums[i-1]) {
                    result.push_back(to_string(start));
                }
                // Otherwise, add range in "start->end" format
                else {
                    result.push_back(to_string(start) + "->" + to_string(nums[i-1]));
                }
                
                // Start new range if not at end
                if (i < nums.size()) {
                    start = nums[i];
                }
            }
        }
        
        return result;
    }
};
// Let's break down how this solution works:

// Approach:
// Iterate through the array once
// Track the start of each range
// When a sequence breaks, add the completed range to result
// Handle single numbers vs. ranges differently
// Key Logic:
// A sequence breaks when current number ≠ previous + 1
// Use start to track range beginning
// Check each number against its predecessor
// Format output based on range length
// Time and Space Complexity:
// Time Complexity: O(n) where n is array length
// Space Complexity: O(1) excluding output space (O(n) including output)
// Example 1 Walkthrough:
// text
// Wrap
// Copy
// nums = [0,1,2,4,5,7]
// - i=1: 1=0+1, continue
// - i=2: 2=1+1, continue
// - i=3: 4≠2+1, add "0->2", start=4
// - i=4: 5=4+1, continue
// - i=5: 7≠5+1, add "4->5", start=7
// - i=6: end, add "7"
// Output: ["0->2","4->5","7"]
// Edge Cases Handled:
// Empty array → empty result
// Single element → single string
// All consecutive numbers → one range
// All separate numbers → individual strings
// The solution handles all test cases:

// [0,1,2,4,5,7] → ["0->2","4->5","7"]
// [0,2,3,4,6,8,9] → ["0","2->4","6","8->9"]
// Key Features:

// Uses array sorted property
// Handles 32-bit integer range
// Produces minimal ranges
// Formats output as required ("a->b" or "a")
// Works with unique values
// The implementation is efficient and straightforward, making a single pass through the array while building the result vector. It correctly identifies consecutive sequences and formats them according to the problem specifications while meeting all constraints.