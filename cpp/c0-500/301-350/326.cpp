Iterative Solution (using division):
cpp
Wrap
Copy
class Solution {
public:
    bool isPowerOfThree(int n) {
        // Handle non-positive numbers
        if (n <= 0) return false;
        
        // Keep dividing by 3 until we can't anymore
        while (n > 1) {
            if (n % 3 != 0) return false;
            n /= 3;
        }
        
        return true;
    }
};
Mathematical Solution (using logarithm):
cpp
Wrap
Copy
#include <cmath>

class Solution {
public:
    bool isPowerOfThree(int n) {
        // Handle non-positive numbers
        if (n <= 0) return false;
        
        // log3(n) = log(n) / log(3)
        // If n is power of 3, this should be an integer
        double logResult = log10(n) / log10(3);
        return abs(logResult - round(logResult)) < 1e-10;
    }
};
Let's analyze both solutions:

Iterative Solution:
How it works:
If n ≤ 0, return false (0 and negative numbers can't be powers of 3)
Repeatedly divide by 3 while checking remainder
If we ever get a non-zero remainder, it's not a power of 3
If we reach 1, it is a power of 3
Time Complexity: O(log n)
Space Complexity: O(1)
Advantages: Simple to understand, no floating-point operations
Mathematical Solution:
How it works:
Uses logarithm property: if n = 3^x, then x = log(n)/log(3)
If x is an integer, n is a power of 3
Uses log10 instead of natural log for better precision
Checks if result is very close to an integer (due to floating-point imprecision)
Time Complexity: O(1)
Space Complexity: O(1)
Advantages: Constant time, elegant mathematical approach
Test cases:

cpp
Wrap
Copy
#include <iostream>

int main() {
    Solution solution;
    
    // Test case 1: 27 = 3^3
    cout << boolalpha << solution.isPowerOfThree(27) << endl;  // true
    
    // Test case 2: 0
    cout << solution.isPowerOfThree(0) << endl;  // false
    
    // Test case 3: -1
    cout << solution.isPowerOfThree(-1) << endl;  // false
    
    // Additional test cases
    cout << solution.isPowerOfThree(1) << endl;   // true (3^0)
    cout << solution.isPowerOfThree(9) << endl;   // true (3^2)
    cout << solution.isPowerOfThree(45) << endl;  // false
    
    return 0;
}
Both solutions handle all constraints:

Work with integers from -2^31 to 2^31 - 1
Correctly identify powers of 3 (1, 3, 9, 27, 81, ...)
Return false for non-powers of 3
The iterative solution might be preferred in practice because:

It avoids floating-point precision issues
It's more intuitive to understand
It doesn't require math library inclusion
However, the mathematical solution is faster for large numbers and shows an elegant alternative approach using logarithms.

Choose the iterative solution if precision and simplicity are priorities, or the mathematical solution if performance is the main concern and you can tolerate minimal floating-point imprecision (handled by the epsilon check).






