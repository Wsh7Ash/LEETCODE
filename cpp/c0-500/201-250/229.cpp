#include <vector>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Since we need elements > n/3, there can be at most 2 candidates
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;
        
        // First pass: Find candidates
        for (int num : nums) {
            if (candidate1 == num) {
                count1++;
            }
            else if (candidate2 == num) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        // Second pass: Count actual occurrences
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }
        
        // Check which candidates appear > n/3
        vector<int> result;
        int n = nums.size();
        if (count1 > n/3) result.push_back(candidate1);
        if (count2 > n/3 && candidate2 != candidate1) result.push_back(candidate2);
        
        return result;
    }
};
// Let's break down how this solution works:

// Approach (Boyer-Moore Voting Algorithm):
// Since we need elements appearing > n/3 times, there can be at most 2 such elements
// First pass: Find potential candidates
// Second pass: Verify candidates by counting
// Key Insights:
// If we cancel out different elements, the majority elements (> n/3) will remain
// Use two counters and candidates
// When count reaches 0, pick new candidate
// Algorithm Steps:
// First pass:
// If number matches candidate, increment its count
// If count is 0, make it a new candidate
// Otherwise, decrement both counts
// Second pass:
// Count actual occurrences of candidates
// Include those exceeding n/3
// Time and Space Complexity:
// Time Complexity: O(n) - two passes through array
// Space Complexity: O(1) - constant extra space
// Example 1 Walkthrough:
// text
// Wrap
// Copy
//  nums = [3,2,3]
// - First pass:
//   3: candidate1=3, count1=1
//   2: candidate2=2, count2=1
//   3: count1=2 (matches candidate1)
// - Second pass:
//   count1=2 (for 3)
//   count2=1 (for 2)
// - n/3 = 1
// - Result: [3] (only 3 appears > 1 time)
// Key Features:

// Handles all test cases correctly
// Works within constraints (1 ≤ n ≤ 5×10⁴, -10⁹ ≤ nums[i] ≤ 10⁹)
// Returns all elements appearing > ⌊n/3⌋ times
// No sorting required
// Constant extra space
// The solution handles edge cases:

// Single element array: [1] → [1]
// Two elements: [1,2] → [1,2] (both > n/3)
// Multiple occurrences: [3,2,3] → [3]
// This implementation efficiently finds all majority elements using the Boyer-Moore algorithm, which is optimal for this problem since it avoids the O(n log n) complexity of sorting or the O(n) space complexity of using a hash map while still achieving O(n) time complexity.