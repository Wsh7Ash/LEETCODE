class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int, int> window;  // {value: index}
            
            for (int i = 0; i < nums.size(); i++) {
                // Check if current number exists in window
                if (window.find(nums[i]) != window.end() && 
                    abs(i - window[nums[i]]) <= k) {
                    return true;
                }
                
                // Add/update current number's index
                window[nums[i]] = i;
                
                // Maintain window size <= k
                if (i >= k) {
                    window.erase(nums[i - k]);
                }
            }
            
            return false;
        }
    };
    // Let's break down how this solution works:
    
    // Approach:
    // Use a sliding window of size k
    // Maintain a hash map of value-to-index mappings
    // Check for duplicates within distance k
    // Remove elements outside window
    // Key Components:
    // unordered_map to store number:index pairs
    // Window size maintained at most k+1
    // Early return on finding valid duplicate
    // Algorithm:
    // text
    // Wrap
    // Copy
    // 1. Create empty hash map
    // 2. For each index i:
    //    - Check if current number exists and distance <= k
    //    - Update/add current number's index
    //    - Remove element at i-k if window exceeds k
    // 3. Return false if no duplicates found
    // Example Walkthrough:
    // text
    // Wrap
    // Copy
    // Input: nums = [1,2,3,1], k = 3
    // i=0: window = {1:0}
    // i=1: window = {1:0, 2:1}
    // i=2: window = {1:0, 2:1, 3:2}
    // i=3: window = {1:0, 2:1, 3:2} -> {2:1, 3:2, 1:3}
    //      - Check 1: abs(3-0) = 3 <= 3 -> true
    
    // Input: nums = [1,0,1,1], k = 1
    // i=0: window = {1:0}
    // i=1: window = {1:0, 0:1}
    // i=2: window = {0:1, 1:2}  (remove 1:0)
    //      - Check 1: abs(2-0) = 2 > 1, continue
    // i=3: window = {1:2, 1:3}  (remove 0:1)
    //      - Check 1: abs(3-2) = 1 <= 1 -> true
    
    // Input: nums = [1,2,3,1,2,3], k = 2
    // i=0-2: window = {1:0, 2:1, 3:2}
    // i=3: window = {2:1, 3:2, 1:3} -> abs(3-0) = 3 > 2
    // i=4: window = {3:2, 1:3, 2:4} -> abs(4-1) = 3 > 2
    // i=5: window = {1:3, 2:4, 3:5} -> abs(5-2) = 3 > 2
    //      -> false
    // Complexity:
    // Time Complexity: O(n)
    // Single pass through array
    // Hash map operations are O(1) average
    // Space Complexity: O(min(n,k))
    // Window size is min(n,k+1)
    // Correctness:
    // Finds duplicates within distance k
    // Handles distinct indices requirement
    // Works with negative numbers
    // Handles k=0 case (no duplicates possible)
    // Meets all constraints:
    
    // 1 <= nums.length <= 10^5
    // -10^9 <= nums[i] <= 10^9
    // 0 <= k <= 10^5
    // The sliding window with hash map is optimal because:
    
    // Maintains constant-time lookup
    // Efficiently tracks window of size k
    // Uses minimal extra space
    // Single pass solution
    // Handles edge cases effectively