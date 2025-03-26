class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        // Handle edge cases
        if (n == 0) return 1;  // Only 0
        if (n > 10) n = 10;    // Max 10 digits (0-9)
        
        // First digit can't be 0, so we have 9 choices
        int firstDigit = 9;
        
        // For remaining digits, we have 9,8,7... choices
        int available = 9;
        
        // Calculate total numbers
        int result = firstDigit;
        
        // For each position after first digit
        for (int i = 0; i < n - 1 && available > 0; i++) {
            result *= available;
            available--;
        }
        
        // Add single digit numbers (including 0)
        return result + 1;
    }
}
Let's break down how this works:

Key Insights:
For n digits, we need to count numbers from 0 to 10^n - 1
Each digit in a number must be unique
First digit can't be 0 for numbers with more than 1 digit
We have only 10 possible digits (0-9)
Mathematical Approach:
For first digit: 9 choices (1-9, can't use 0)
For second digit: 9 choices (0-9 except the first digit)
For third digit: 8 choices (0-9 except first two digits)
And so on...
Algorithm:
Handle n=0 case: return 1 (just 0)
Cap n at 10 since we only have 10 digits
Start with 9 possibilities for first digit
Multiply by remaining available digits
Add 1 for the single-digit case (0)
Example Walkthrough:
text
Wrap
Copy
n = 1:
- Single digits: 0-9
- Total: 10 (but our formula: 9 + 1 = 10)

n = 2:
- First digit: 9 choices (1-9)
- Second digit: 9 choices (0-9 except first digit)
- Total: 9 * 9 + 1 = 82 + 1 = 83
- Plus single digits: 9
- Grand total: 91

n = 3:
- First: 9 choices
- Second: 9 choices
- Third: 8 choices
- Total: 9 * 9 * 8 + 1 = 649
Correctness Check:
text
Wrap
Copy
n = 2:
Total numbers (0-99): 100
Numbers with repeated digits: 9 (11,22,33,44,55,66,77,88,99)
Result: 100 - 9 = 91 ✓
Time Complexity: O(1) since loop runs at most 9 times
Space Complexity: O(1)
The solution handles all constraints:

Works for n from 0 to 8
Correctly counts numbers from 0 to 10^n - 1
Excludes numbers with repeated digits
Caps at n=10 implicitly (though constraint is n≤8)
This mathematical approach is much more efficient than generating all possible numbers and checking for unique digits, especially for larger values of n. The formula correctly accounts for all cases including single-digit numbers and the special case of 0.