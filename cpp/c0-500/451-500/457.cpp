#include <vector>

class Solution {
private:
    int getNextIndex(int curr, int n, std::vector<int>& nums) {
        // Calculate next index with circular wrap-around
        long long next = (curr + nums[curr]) % n;
        // Handle negative modulo
        if (next < 0) next += n;
        return next;
    }
    
public:
    bool circularArrayLoop(std::vector<int>& nums) {
        int n = nums.size();
        
        // Try each starting position
        for (int i = 0; i < n; i++) {
            // Skip if we've already processed this index
            if (nums[i] == 0) continue;
            
            int slow = i;
            int fast = i;
            bool isForward = nums[i] > 0;  // Direction of first move
            
            do {
                // Move slow pointer one step
                slow = getNextIndex(slow, n, nums);
                
                // If direction changes or cycle of length 1, break
                if ((nums[slow] > 0) != isForward || slow == getNextIndex(slow, n, nums)) {
                    slow = -1;  // Mark as invalid
                    break;
                }
                
                // Move fast pointer two steps
                fast = getNextIndex(fast, n, nums);
                if ((nums[fast] > 0) != isForward || fast == getNextIndex(fast, n, nums)) {
                    slow = -1;  // Mark as invalid
                    break;
                }
                fast = getNextIndex(fast, n, nums);
                if ((nums[fast] > 0) != isForward) {
                    slow = -1;  // Mark as invalid
                    break;
                }
                
            } while (slow != fast);
            
            // If we found a valid cycle
            if (slow != -1) {
                return true;
            }
            
            // Mark all visited nodes as processed
            slow = i;
            while (nums[slow] != 0) {
                int next = getNextIndex(slow, n, nums);
                nums[slow] = 0;
                slow = next;
            }
        }
        
        return false;
    }
};
Let's break down how this solution works:

Approach:
Use Floyd's cycle-finding algorithm with two pointers (slow and fast)
Check for same direction in cycle
Ensure cycle length > 1
Mark visited nodes to avoid reprocessing
Key Components:
getNextIndex: Handles circular movement and negative numbers
Main loop:
Slow pointer moves 1 step
Fast pointer moves 2 steps
Checks direction consistency
Checks for length-1 cycles
Marks visited nodes as 0 after exploration
Time Complexity: O(n)
Each element is visited at most twice
Cycle detection is O(n) per starting point
Space Complexity: O(1)
Only uses constant extra space
Modifies input array to mark visited nodes
Example walkthrough:

Example 1: [2,-1,1,2,2]

Start at 0:
Cycle detected: 0->2->3->0
All positive moves
Length > 1
Returns true
Example 2: [-1,-2,-3,-4,-5,6]

Each position leads to either:
Length-1 cycle (self-loop)
Mixed directions
Returns false
Example 3: [1,-1,5,1,4]

0->1->0 has mixed directions
3->4->3 is all positive and length > 1
Returns true
The solution handles all constraints:

Works for 1 <= n <= 5000
Handles -1000 <= nums[i] <= 1000
Accounts for nums[i] != 0
Correctly identifies valid cycles with:
Length > 1
Consistent direction
Circular movement