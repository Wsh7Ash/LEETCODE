#include <vector>
using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        
        // If length < 4, no crossing possible (need at least 4 moves)
        if (n < 4) return false;
        
        // Check three possible crossing scenarios
        for (int i = 3; i < n; i++) {
            // Case 1: Fourth line crosses first line
            // North crosses previous south
            if (i >= 3 && 
                distance[i-3] >= distance[i-1] &&  // Previous south >= current north
                distance[i] >= distance[i-2]) {     // Current east >= previous west
                return true;
            }
            
            // Case 2: Fifth line crosses first line
            // West crosses previous south
            if (i >= 4 && 
                distance[i-4] >= (distance[i-2] - distance[i]) && // Previous south >= (current west - previous east)
                distance[i-1] >= distance[i-3] &&                  // Current north >= previous north
                distance[i-2] >= distance[i]) {                    // Previous west >= current east
                return true;
            }
            
            // Case 3: Sixth line crosses first line
            // South crosses previous south
            if (i >= 5 && 
                distance[i-5] >= (distance[i-3] - distance[i-1]) && // Previous previous south >= (previous north - current north)
                distance[i-4] >= (distance[i-2] - distance[i]) &&   // Previous south >= (current west - previous east)
                distance[i-3] >= distance[i-1] &&                   // Previous north >= current north
                distance[i-2] >= distance[i] &&                     // Previous west >= current east
                distance[i-1] <= distance[i-3]) {                   // Current north <= previous north
                return true;
            }
        }
        
        return false;
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> distance1 = {2, 1, 1, 2};
    cout << boolalpha << solution.isSelfCrossing(distance1) << endl;  // true
    
    // Test case 2
    vector<int> distance2 = {1, 2, 3, 4};
    cout << solution.isSelfCrossing(distance2) << endl;  // false
    
    // Test case 3
    vector<int> distance3 = {1, 1, 1, 2, 1};
    cout << solution.isSelfCrossing(distance3) << endl;  // true
    
    return 0;
}
How it works:

Key Insight:
A path can only cross itself in three main patterns
All crossings involve comparing current move with previous moves
Directions cycle: North → West → South → East
Crossing Patterns:
Case 1 (i=3): Fourth line (east) crosses first line (north)
Previous south ≥ current north AND current east ≥ previous west
Case 2 (i=4): Fifth line (west) crosses first line (north)
More complex conditions involving multiple previous moves
Case 3 (i=5): Sixth line (south) crosses first line (north)
Most complex case with multiple conditions
Algorithm:
Check each position starting from i=3
For each position, check all applicable crossing cases
Return true if any crossing condition is met
Return false if no crossings found
Example Walkthrough for [2,1,1,2]:
N(2): (0,0)→(0,2)
W(1): (0,2)→(-1,2)
S(1): (-1,2)→(-1,1)
E(2): (-1,1)→(1,1)
Case 1: 2≥1 && 2≥1 → true (crosses at (0,1))
Complexity:

Time Complexity: O(n) - single pass through array
Space Complexity: O(1) - no extra space used
The solution satisfies all constraints:

Works for array length 1 to 10^5
Handles distances 1 to 10^5
For the examples:

[2,1,1,2] → true (fourth line crosses first)
[1,2,3,4] → false (no crossing)
[1,1,1,2,1] → true (fifth line crosses first)
This solution efficiently detects self-crossing by:

Only checking necessary conditions
Using simple comparisons
Avoiding actual coordinate tracking
Handling all possible crossing patterns