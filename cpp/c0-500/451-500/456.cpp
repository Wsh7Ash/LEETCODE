#include <vector>
#include <stack>

class Solution {
public:
    bool find132pattern(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        
        std::stack<int> st;  // Stack to keep track of potential nums[j]
        int s2 = INT_MIN;    // Maximum value that could be nums[k]
        
        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // If we find a number smaller than s2, we found our pattern
            if (nums[i] < s2) {
                return true;
            }
            
            // While stack isn't empty and current number is greater than top
            while (!st.empty() && nums[i] > st.top()) {
                // Update s2 with the largest number less than nums[i]
                s2 = st.top();
                st.pop();
            }
            
            // Push current number as potential nums[j]
            st.push(nums[i]);
        }
        
        return false;
    }
};
Let's break down how this solution works:

Approach:
Process array from right to left
Use stack to maintain potential nums[j] values
Keep track of maximum nums[k] (s2) that's less than stack top
Look for nums[i] that's less than s2
Algorithm:
If array size < 3, return false
For each number from right to left:
If current < s2: found 132 pattern (current is nums[i])
While current > stack top:
Update s2 with popped values (potential nums[k])
Push current number (potential nums[j])
If no pattern found, return false
Time Complexity: O(n)
Single pass through array
Each element pushed/popped at most once
Space Complexity: O(n)
Stack might store up to n elements in worst case
Example walkthrough:

Example 2: [3,1,4,2]

i=3: stack=[2], s2=INT_MIN
i=2: 4>2, stack=[4], s2=2
i=1: 1<2, return true (1<4>2)
Result: true
Example 3: [-1,3,2,0]

i=3: stack=[0], s2=INT_MIN
i=2: 2>0, stack=[2], s2=0
i=1: 3>2, stack=[3], s2=2
i=0: -1<2, return true (-1<3>2)
Result: true
Example 1: [1,2,3,4]

i=3: stack=[4], s2=INT_MIN
i=2: stack=[4,3], s2=INT_MIN
i=1: stack=[4,3,2], s2=INT_MIN
i=0: stack=[4,3,2,1], s2=INT_MIN
Result: false
The solution handles all constraints:

Works for n between 1 and 2×10⁵
Handles values between -10⁹ and 10⁹
Correctly identifies 132 pattern when it exists