#include <iostream>
using namespace std;

class Solution {
public:
    // Solution 1: Bit Manipulation
    bool isPowerOfFour(int n) {
        // Check if n is positive and has only one 1-bit in an even position
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
    }
    
    // Solution 2: Mathematical Approach
    bool isPowerOfFourMath(int n) {
        // Check if n is positive and log4(n) is an integer
        if (n <= 0) return false;
        int log4 = log2(n) / 2;  // log4(n) = log2(n)/log2(4)
        return pow(4, log4) == n;
    }
};

// Test code
int main() {
    Solution solution;
    
    // Test case 1
    cout << boolalpha << solution.isPowerOfFour(16) << endl;  // true
    
    // Test case 2
    cout << solution.isPowerOfFour(5) << endl;  // false
    
    // Test case 3
    cout << solution.isPowerOfFour(1) << endl;  // true
    
    // Additional test cases
    cout << solution.isPowerOfFour(4) << endl;   // true
    cout << solution.isPowerOfFour(64) << endl;  // true
    cout << solution.isPowerOfFour(0) << endl;   // false
    cout << solution.isPowerOfFour(-4) << endl;  // false
    
    return 0;
}
Let's analyze both solutions:

Bit Manipulation Solution:
cpp
Wrap
Copy
bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
}
How it works:
n > 0: Powers of 4 must be positive
(n & (n - 1)) == 0: Checks if n is a power of 2 (has only one 1-bit)
(n & 0xAAAAAAAA) == 0: Checks if the 1-bit is in an even position (0,2,4,...)
0xAAAAAAAA has 1s in odd positions only
Examples:
4 (100) → true
16 (10000) → true
8 (1000) → false (power of 2 but not 4)
Mathematical Solution:
cpp
Wrap
Copy
bool isPowerOfFourMath(int n) {
    if (n <= 0) return false;
    int log4 = log2(n) / 2;
    return pow(4, log4) == n;
}
How it works:
Checks if n is positive
Computes log4(n) using log2(n)/2
Verifies if 4^log4 equals n exactly
Note: This solution might have floating-point precision issues for very large numbers
Complexity:

Bit Manipulation:
Time: O(1)
Space: O(1)
Mathematical:
Time: O(1)
Space: O(1)
Key Features:

Both handle negative numbers
Both identify powers of 4 (1, 4, 16, 64, ...)
Bit manipulation is more precise and efficient
The bit manipulation solution is preferred because:

No floating-point operations
More efficient bit operations
No precision issues
Simpler to understand
The solution satisfies all constraints:

Works for -2^31 to 2^31-1
Correctly identifies powers of 4
For the examples:

16 → true (4^2)
5 → false (not a power of 4)
1 → true (4^0)
Additional powers of 4:

4 (4^1) → true
64 (4^3) → true
0 → false
-4 → false
The bit manipulation solution efficiently checks for powers of 4 by:

Ensuring single bit (power of 2)
Verifying bit position (even positions only)
Handling edge cases naturally