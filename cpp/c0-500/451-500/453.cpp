#include <vector>
#include <algorithm>

class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        
        // Find the minimum element
        long long minNum = *std::min_element(nums.begin(), nums.end());
        
        // Calculate total moves needed
        long long moves = 0;
        for (int num : nums) {
            moves += num - minNum;
        }
        
        return moves;
    }
};
Let's break down how this works:

Mathematical Insight:
Instead of incrementing n-1 elements up, think of decrementing 1 element down
All elements must eventually equal some value k
The optimal k is the minimum element in the array
Total moves = sum of differences between each element and the minimum
Algorithm:
Find the minimum element in the array
For each element, calculate how many moves (increments of others) are needed to equal the minimum
Sum all these differences
Implementation Details:
Use long long to avoid integer overflow during summation
Base case: if array size ≤ 1, return 0
Use std::min_element for efficiency
Time Complexity: O(n) - one pass to find minimum, one pass to sum differences Space Complexity: O(1) - only using constant extra space
Example 1: [1,2,3]

minNum = 1
moves = (1-1) + (2-1) + (3-1) = 0 + 1 + 2 = 3
Result: 3
Verification:
[1,2,3] -> [2,3,3] (increment 1,2)
[2,3,3] -> [3,4,3] (increment 2,3)
[3,4,3] -> [4,4,4] (increment 3,4)
3 moves total
Example 2: [1,1,1]

minNum = 1
moves = (1-1) + (1-1) + (1-1) = 0 + 0 + 0 = 0
Result: 0 (already equal)
The solution handles all constraints:

Works for n between 1 and 10^5
Handles numbers between -10^9 and 10^9
Returns result fits in 32-bit integer (using long long ensures no overflow during calculation)
Single pass through the array makes it efficient