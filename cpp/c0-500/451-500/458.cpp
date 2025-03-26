#include <cmath>

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // Calculate number of tests possible plus 1 (for no death case)
        int tests = minutesToTest / minutesToDie;
        int states = tests + 1;  // Each pig can be in (tests + 1) states
        
        // We need: states^pigs >= buckets
        // Taking log: pigs >= log(buckets) / log(states)
        return ceil(log(buckets) / log(states));
    }
};
Let's break down how this works:

Core Concept:
Each pig can be in (tests + 1) states:
Dies in test 1
Dies in test 2
...
Dies in test n
Doesn't die
Total possible combinations = (tests + 1)^pigs
We need this to be >= number of buckets
Mathematical Solution:
tests = minutesToTest / minutesToDie (integer division)
states = tests + 1
pigs = ceil(log(buckets) / log(states))
This gives us the minimum number of pigs needed
Time Complexity: O(1)
Just simple arithmetic operations
Space Complexity: O(1)
Only uses a few variables
Example walkthroughs:

Example 1: buckets=4, minutesToDie=15, minutesToTest=15

tests = 15/15 = 1
states = 1 + 1 = 2
log(4)/log(2) = 2
Result: 2 pigs
Verification:
2 pigs can represent 2²=4 states
Enough for 4 buckets
Example 2: buckets=4, minutesToDie=15, minutesToTest=30

tests = 30/15 = 2
states = 2 + 1 = 3
log(4)/log(3) ≈ 1.2619
ceil(1.2619) = 2
Result: 2 pigs
Verification:
2 pigs can represent 3²=9 states
More than enough for 4 buckets
Why this works:

For n pigs with k tests, we get (k+1)^n possible outcomes
Each bucket needs a unique outcome to identify it
We need minimum n where (k+1)^n ≥ buckets
The log formula gives us exactly this number
The solution handles all constraints:

Works for 1 <= buckets <= 1000
Works for 1 <= minutesToDie <= minutesToTest <= 100
Returns integer result
Mathematically guaranteed to find minimum pigs needed