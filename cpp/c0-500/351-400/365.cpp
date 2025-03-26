class Solution {
    public boolean canMeasureWater(int x, int y, int target) {
        // If total capacity is less than target, impossible
        if (x + y < target) {
            return false;
        }
        
        // If one jug is 0, target must equal other jug or 0
        if (x == 0 || y == 0) {
            return target == 0 || target == (x + y);
        }
        
        // Target must be a multiple of GCD of x and y
        return target % gcd(x, y) == 0;
    }
    
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
Let's break down how this works:

Mathematical Foundation:
Bézout's identity: If d = gcd(x,y), then any number achievable must be a multiple of d
Any amount that can be measured must be of form ax + by where a,b are integers
The smallest positive amount measurable is gcd(x,y)
Key Insights:
If target > x + y, it's impossible (not enough capacity)
If one jug is 0, target must equal the other jug's capacity or 0
For non-zero x and y, target must be a multiple of their GCD
Maximum achievable is x + y
Algorithm:
Check if target exceeds total capacity
Handle cases where one jug has 0 capacity
Compute GCD and check if target is a multiple of it
Example Walkthrough:
text
Wrap
Copy
Example 1: x=3, y=5, target=4
- x + y = 8 ≥ 4 ✓
- gcd(3,5) = 1
- 4 % 1 = 0 ✓
- Result: true

Example 2: x=2, y=6, target=5
- x + y = 8 ≥ 5 ✓
- gcd(2,6) = 2
- 5 % 2 = 1 ≠ 0
- Result: false

Example 3: x=1, y=2, target=3
- x + y = 3 ≥ 3 ✓
- gcd(1,2) = 1
- 3 % 1 = 0 ✓
- Result: true
Time Complexity: O(log(min(x,y))) due to GCD calculation
Space Complexity: O(1)
Why It Works:
The operations (fill, empty, pour) can generate any multiple of gcd(x,y)
Can't generate amounts that aren't multiples of gcd
Total capacity constraint is checked first
Special cases (x=0 or y=0) are handled correctly
The solution meets all constraints:

Works for 1 ≤ x,y,target ≤ 10³
Correctly determines if target is achievable
Handles all possible operation combinations implicitly through GCD
This mathematical solution is much more efficient than BFS/DFS approaches that simulate all possible states, especially for larger jug capacities. It leverages number theory to provide a direct answer without explicitly tracking water pouring steps.