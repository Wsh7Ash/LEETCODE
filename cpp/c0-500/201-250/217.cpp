// For this Contains Duplicate problem, I'll provide a few approaches with different trade-offs. The most efficient solution typically uses a hash set. Here's the C++ solution using an unordered_set:

// cpp
// Wrap
// Copy
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int num : nums) {
            // If insertion fails (element already exists), we found a duplicate
            if (!seen.insert(num).second) {
                return true;
            }
        }
        
        return false;
    }
};
// Alternative solution using sorting (less space-efficient but no extra data structure):

// cpp
// Wrap
// Copy
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.length(); i++) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }
};
// Let's break down the hash set solution (first one):

// Approach:
// Use an unordered_set to track seen numbers
// Insert each number and check if it already exists
// Return true on first duplicate, false if none found
// Key Details:
// unordered_set::insert returns pair<iterator, bool>
// second element is false if element already exists
// Early return on duplicate detection
// Single pass through array
// Algorithm:
// text
// Wrap
// Copy
// 1. Create empty hash set
// 2. For each number in array:
//    - Try to insert into set
//    - If insertion fails, return true
// 3. If loop completes, return false
// Example Walkthrough:
// text
// Wrap
// Copy
// Input: [1,2,3,1]
// - seen = {}
// - num = 1: seen = {1}
// - num = 2: seen = {1,2}
// - num = 3: seen = {1,2,3}
// - num = 1: insert fails (1 exists) -> return true

// Input: [1,2,3,4]
// - seen = {}
// - num = 1: seen = {1}
// - num = 2: seen = {1,2}
// - num = 3: seen = {1,2,3}
// - num = 4: seen = {1,2,3,4}
// - No duplicates -> return false
// Complexity:
// Time Complexity: O(n)
// Single pass through array
// Hash set operations are O(1) average case
// Space Complexity: O(n)
// Worst case stores all elements in hash set
// Worst Time: O(n) even with hash collisions
// Comparison with Sorting:
// Hash Set:
// Time: O(n)
// Space: O(n)
// Doesn't modify input
// Sorting:
// Time: O(n log n)
// Space: O(1) or O(log n) for sort
// Modifies input array
// Correctness:
// Detects any duplicate value
// Returns false for distinct elements
// Handles single-element arrays
// Works with negative numbers
// Meets all constraints:

// 1 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9
// The hash set approach is preferred because:

// Optimal time complexity O(n)
// Preserves original array
// Simple implementation
// Early termination on duplicate
// Handles large ranges efficiently
// The choice between solutions might depend on:

// Whether modifying input is allowed
// Memory constraints
// Input size and range
// Need for early termination