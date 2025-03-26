Let's solve this problem of repeatedly adding digits until we get a single digit. There are two approaches: one using iteration and another using a mathematical formula (digital root). I'll provide both solutions in C++, with the mathematical one being more efficient.

Solution 1 (Iterative Approach):

cpp
Wrap
Copy
class Solution {
public:
    int addDigits(int num) {
        // Keep adding digits until we get a single digit
        while (num > 9) {
            int sum = 0;
            // Extract and add each digit
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};
Solution 2 (Mathematical Approach - Digital Root):

cpp
Wrap
Copy
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};
// Let's break down both solutions:

// Iterative Approach:
// Repeatedly:
// Extracts each digit using modulo (%) and division (/)
// Adds digits together
// Continues until result is single digit
// Time Complexity: O(log n) - depends on number of digits
// Space Complexity: O(1)
// Mathematical Approach:
// Uses the concept of digital root
// Based on the mathematical property that the single-digit result follows a pattern with modulo 9
// Formula: if num = 0, return 0; if num % 9 = 0, return 9; else return num % 9
// Time Complexity: O(1)
// Space Complexity: O(1)
// Why the mathematical approach works (Digital Root):

// This is based on the congruence formula: dr(n) = 1 + ((n-1) mod 9) if n > 0, else 0
// Simplified to: num % 9, with special cases for 0 and multiples of 9
// Examples:
// 38: 38 % 9 = 2
// 18: 18 % 9 = 0, so return 9
// 0: return 0
// Example walkthrough (num = 38):

// Iterative:
// 38: 3 + 8 = 11
// 11: 1 + 1 = 2
// Return 2
// Mathematical:
// 38 % 9 = 2
// Return 2
// The mathematical solution is more efficient as it doesn't need to process individual digits. Both solutions satisfy the constraints:

// Works for 0 <= num <= 2^31 - 1
// Returns a single digit
// Handles edge case of 0 correctly
// I recommend using the mathematical solution for its O(1) time complexity, unless you're specifically asked to show the iterative process.