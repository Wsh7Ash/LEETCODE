#include <algorithm>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        // Base cases
        if (n == 2) return 1;  // 1 * 1
        if (n == 3) return 2;  // 1 * 2
        
        // For n >= 4, optimal solution uses mostly 3s
        int countOfThrees = n / 3;  // Number of 3s we can use
        int remainder = n % 3;      // Remaining value
        
        if (remainder == 0) {
            // All 3s
            return pow(3, countOfThrees);
        } else if (remainder == 1) {
            // Replace one 3 with a 4 (3+1=4 gives better product)
            return pow(3, countOfThrees - 1) * 4;
        } else {  // remainder == 2
            // Use one 2 with the 3s
            return pow(3, countOfThrees) * 2;
        }
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    // Test case 1
    cout << solution.integerBreak(2) << endl;  // 1
    
    // Test case 2
    cout << solution.integerBreak(10) << endl;  // 36
    
    // Additional test cases
    cout << solution.integerBreak(3) << endl;  // 2
    cout << solution.integerBreak(4) << endl;  // 4
    cout << solution.integerBreak(8) << endl;  // 18
    
    return 0;
}
How it works:

Mathematical Insight:
For n ≥ 4, breaking into factors of 3 gives maximum product
2 < 3 < 4 in terms of growth rate, but:
Two 2s (4) > one 3 (3)
Three 3s (27) > two 4s (16)
Optimal strategy: use as many 3s as possible, handle remainder with 2 or 4
Algorithm:
Handle base cases (n=2, n=3) directly
For n ≥ 4:
Calculate number of 3s (n/3)
Handle remainder (n%3):
0: all 3s
1: replace one 3 with 4 (3+1=4)
2: add one 2
Example Walkthrough for n=10:
countOfThrees = 10/3 = 3
remainder = 10%3 = 1
Since remainder=1: use (3-1) 3s and one 4
Result: 3^2 * 4 = 9 * 4 = 36
Complexity:

Time Complexity: O(1) - constant time operations
Space Complexity: O(1) - no extra space
Key Features:

Optimal use of mathematical properties
Handles all cases efficiently
No need for recursion or DP array
The solution satisfies all constraints:

Works for n from 2 to 58
Returns maximum possible product
For the examples:

n=2 → 1 (1*1)
n=10 → 36 (334)
Additional examples:

n=3 → 2 (1*2)
n=4 → 4 (2*2)
n=8 → 18 (332)
This solution is efficient because:

Uses mathematical optimization instead of brute force
Avoids expensive iterations or recursion
Directly computes maximum product
Handles edge cases explicitly
The key mathematical insight is that:

3 is the most "efficient" factor (maximizes product per unit)
Remainders are optimally handled with 2 or 4
Larger factors (5,6,etc.) are less efficient than multiple 3s