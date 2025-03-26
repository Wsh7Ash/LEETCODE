#include <string>
#include <stack>

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;    // Stack for numbers
        stack<int> signs;   // Stack for signs (1 for +, -1 for -)
        int result = 0;     // Running result
        int num = 0;        // Current number being built
        int sign = 1;       // Current sign (1 for +, -1 for -)
        
        for (char c : s) {
            if (isdigit(c)) {
                // Build multi-digit number
                num = num * 10 + (c - '0');
            }
            else if (c == '+' || c == '-') {
                // Add previous number to result and reset for next number
                result += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            }
            else if (c == '(') {
                // Push current state to stacks and reset
                nums.push(result);
                signs.push(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')') {
                // Calculate result within parentheses and combine with previous state
                result += sign * num;
                num = 0;
                result = signs.top() * result + nums.top();
                signs.pop();
                nums.pop();
            }
            // Ignore spaces
        }
        
        // Add last number if exists
        result += sign * num;
        
        return result;
    }
};
// Let's break down how this solution works:

// Approach:
// Use two stacks: one for numbers and one for signs to handle nested parentheses
// Process the string character by character
// Build numbers digit by digit
// Handle operators and parentheses appropriately
// Key Components:
// result: running total
// num: current number being built
// sign: current sign (1 or -1)
// nums stack: stores results before parentheses
// signs stack: stores signs before parentheses
// Logic Flow:
// Digit: Build multi-digit number
// or -: Process previous number and set new sign
// (: Save current state and start new calculation
// ): Complete current calculation and combine with previous state
// Space: Ignore
// Time and Space Complexity:
// Time Complexity: O(n) where n is string length
// Space Complexity: O(n) for the stacks in worst case with nested parentheses
// Example 3 Walkthrough:
// text
// Wrap
// Copy
// "(1+(4+5+2)-3)+(6+8)"
// - '('     : push 0,1  result=0, sign=1
// - '1'     : num=1
// - '+'     : result=1, sign=1, num=0
// - '('     : push 1,1  result=0, sign=1
// - '4+5+2' : result=11, sign=1
// - ')'     : result=11, pop 1,1 → result=11+1=12
// - '-'     : result=12, sign=-1
// - '3'     : num=3
// - ')'     : result=12-3=9, pop 0,1 → result=9
// - '+'     : result=9, sign=1
// - '(6+8)' : final result=9+14=23
// The solution handles all cases:

// Simple addition/subtraction (Example 1: "1 + 1")
// Multiple operations (Example 2: " 2-1 + 2 ")
// Nested parentheses (Example 3: "(1+(4+5+2)-3)+(6+8)")
// Key features:

// Handles multi-digit numbers
// Supports negative numbers after parentheses
// Ignores spaces
// No use of eval() or similar functions
// Fits within 32-bit integer constraints
// This implementation efficiently evaluates the expression while meeting all the specified constraints and producing the correct output for all example cases.