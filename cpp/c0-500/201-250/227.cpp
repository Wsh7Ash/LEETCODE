#include <string>

class Solution {
public:
    int calculate(string s) {
        int result = 0;      // Running result
        int currentNum = 0;  // Current number being built
        int lastNum = 0;     // Last number for * and / operations
        char operation = '+'; // Current operation
        
        // Process each character
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            // Build number
            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            }
            
            // Process operator or end of string
            if (!isdigit(c) && c != ' ' || i == s.length() - 1) {
                // Handle previous operation
                if (operation == '+') {
                    result += lastNum;
                    lastNum = currentNum;
                }
                else if (operation == '-') {
                    result += lastNum;
                    lastNum = -currentNum;
                }
                else if (operation == '*') {
                    lastNum = lastNum * currentNum;
                }
                else if (operation == '/') {
                    lastNum = lastNum / currentNum;
                }
                
                // Update operation and reset current number
                operation = c;
                currentNum = 0;
            }
        }
        
        // Add the final number
        result += lastNum;
        
        return result;
    }
};
// Let's break down how this solution works:

// Approach:
// Process string left to right in a single pass
// Handle * and / immediately while delaying + and -
// Use variables to track running result and current operation
// Key Variables:
// result: stores the sum of processed numbers
// currentNum: builds multi-digit numbers
// lastNum: holds the previous number for * and / operations
// operation: tracks the current operator
// Logic Flow:
// Build numbers digit by digit
// When hitting an operator or end:
// Process previous operation
// For + and -: add to result and store new number
// For * and /: multiply/divide immediately
// Handle spaces by ignoring them
// Time and Space Complexity:
// Time Complexity: O(n) where n is string length
// Space Complexity: O(1) - uses only a few variables
// Example 1 Walkthrough:
// text
// Wrap
// Copy
// "3+2*2"
// - '3': currentNum=3
// - '+': result=0, lastNum=3, operation='+'
// - '2': currentNum=2
// - '*': result=3, lastNum=2, operation='*'
// - '2': currentNum=2
// - end: lastNum=2*2=4, result=3+4=7
// Output: 7
// Example 3 Walkthrough:
// text
// Wrap
// Copy
// " 3+5 / 2 "
// - '3': currentNum=3
// - '+': result=0, lastNum=3, operation='+'
// - '5': currentNum=5
// - '/': result=3, lastNum=5, operation='/'
// - '2': currentNum=2
// - end: lastNum=5/2=2, result=3+2=5
// Output: 5
// Key Features:

// Handles operator precedence (* and / before + and -)
// Processes multi-digit numbers
// Ignores spaces
// Truncates division toward zero (C++ default)
// No built-in evaluation functions used
// Fits 32-bit integer constraints
// The solution correctly handles all test cases:

// "3+2*2" → 7
// " 3/2 " → 1
// " 3+5 / 2 " → 5
// This implementation efficiently evaluates the expression while respecting operator precedence and meeting all specified constraints. It's more efficient than using a full stack since we can process multiplication and division on the fly rather than storing all operations.