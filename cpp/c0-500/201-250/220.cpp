class Solution {
    public:
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
            multiset<long> window;  // Use long to avoid integer overflow
            int n = nums.size();
            
            for (int i = 0; i < n; i++) {
                // Maintain window size
                if (i > indexDiff) {
                    window.erase(window.find(nums[i - indexDiff - 1]));
                }
                
                // Convert current number to long to avoid overflow
                long curr = nums[i];
                
                // Find the smallest number >= curr - valueDiff
                auto lower = window.lower_bound(curr - valueDiff);
                
                // If we found a number and it's within valueDiff
                if (lower != window.end() && abs(*lower - curr) <= valueDiff) {
                    return true;
                }
                
                // Insert current number
                window.insert(curr);
            }
            
            return false;
        }
    };
    // Let's break down how this solution works:
    
    // Approach:
    // Use a sliding window of size indexDiff
    // Maintain a multiset of values in the window
    // For each number, check if there's a value within valueDiff
    // Use BST properties to find nearby values efficiently
    // Key Components:
    // multiset: maintains sorted values in window
    // lower_bound: finds first element >= target
    // Window size management: removes old elements
    // Long type: prevents integer overflow
    // Algorithm:
    // text
    // Wrap
    // Copy
    // 1. Create empty multiset
    // 2. For each index i:
    //    - Remove element outside window (i - indexDiff - 1)
    //    - Find lower bound of (curr - valueDiff)
    //    - Check if found value is within valueDiff
    //    - Add current number to window
    // 3. Return false if no match found
    // Example Walkthrough:
    // text
    // Wrap
    // Copy
    // Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
    // i=0: window = {1}
    // i=1: window = {1,2}
    // i=2: window = {1,2,3}
    // i=3: window = {1,2,3,1}
    //      lower_bound(1-0) = 1
    //      abs(1-1) = 0 <= 0 -> true
    
    // Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
    // i=0-2: window = {1,5,9}
    // i=3: window = {5,9,1}, check 1: 5-1=4 > 3
    // i=4: window = {9,1,5}, check 5: 5-1=4 > 3
    // i=5: window = {1,5,9}, check 9: 9-5=4 > 3
    //      -> false
    // Complexity:
    // Time Complexity: O(n log k)
    // n iterations
    // Each BST operation (insert/erase/lower_bound): O(log k)
    // k = min(n, indexDiff + 1)
    // Space Complexity: O(k)
    // Window stores at most indexDiff + 1 elements
    // Correctness:
    // Checks distinct indices (i != j)
    // Ensures abs(i - j) <= indexDiff
    // Verifies abs(nums[i] - nums[j]) <= valueDiff
    // Handles edge cases and overflow
    // Meets all constraints:
    
    // 2 <= nums.length <= 10^5
    // -10^9 <= nums[i] <= 10^9
    // 1 <= indexDiff <= nums.length
    // 0 <= valueDiff <= 10^9
    // The BST approach is optimal because:
    
    // Efficiently finds nearby values
    // Maintains sorted order for range queries
    // Handles window size dynamically
    // Avoids checking all pairs O(n²)
    // Uses logarithmic time for operations
    // Note: We use long instead of int to handle potential overflow when calculating differences between large negative and positive numbers within the given constraints.