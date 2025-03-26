#include <vector>
#include <numeric>
using namespace std;

class Solution {
private:
    bool canMakeSquare(vector<int>& matchsticks, vector<int>& sides, int index, int target) {
        // Base case: all matchsticks used
        if (index == matchsticks.size()) {
            // Check if all sides are equal to target
            return sides[0] == target && sides[1] == target && 
                   sides[2] == target && sides[3] == target;
        }
        
        // Try placing current matchstick in each of the 4 sides
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] <= target) {
                sides[i] += matchsticks[index];
                
                if (canMakeSquare(matchsticks, sides, index + 1, target)) {
                    return true;
                }
                
                sides[i] -= matchsticks[index];
                
                // Optimization: if this side is 0, no need to try other empty sides
                if (sides[i] == 0) break;
            }
        }
        
        return false;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        
        // Calculate total length and check if it can form a square
        int perimeter = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (perimeter % 4 != 0) return false;
        
        int target = perimeter / 4;
        
        // Sort in descending order for optimization
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        
        // If any stick is longer than target, impossible
        if (matchsticks[0] > target) return false;
        
        vector<int> sides(4, 0);
        return canMakeSquare(matchsticks, sides, 0, target);
    }
};
Let's break down how this solution works:

Approach:
Use backtracking to try placing each matchstick in one of 4 sides
Check if we can form 4 equal sides with all matchsticks
Main Function (makesquare):
Initial checks:
Need at least 4 matchsticks
Total length must be divisible by 4
No stick can be longer than target side length
Sort in descending order to fail faster with larger sticks
Call recursive helper function
Helper Function (canMakeSquare):
Parameters:
matchsticks: input array
sides: current length of each side
index: current matchstick being placed
target: required length of each side
Tries placing current matchstick in each side
Uses backtracking by adding and removing matchsticks
Optimizations:
Sort descending: larger numbers fail faster
If a side is 0 and fails, skip other empty sides
Early validation checks
Time Complexity:
Worst case: O(4^N) where N is number of matchsticks
Each matchstick can be placed in 4 sides
Optimizations reduce practical runtime significantly
Space Complexity:
O(N) for recursion stack
O(1) extra space (sides array is fixed size 4)
Example:
[1,1,2,2,2]:
Perimeter = 8, target = 2
Can form: [1,1], [2], [2], [2]
Returns true
[3,3,3,3,4]:
Perimeter = 16, target = 4
Can't form four sides of 4
Returns false
Key Features:
Uses all matchsticks exactly once
Doesn't break any sticks
Handles all constraints
Returns correct boolean result