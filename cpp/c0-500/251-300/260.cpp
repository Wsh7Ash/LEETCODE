#include <vector>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        // Step 1: XOR all numbers to get XOR of the two unique numbers
        int xorAll = 0;
        for (int num : nums) {
            xorAll ^= num;
        }
        
        // Step 2: Find a set bit in xorAll (using rightmost set bit)
        int rightmostSetBit = xorAll & -xorAll;
        
        // Step 3: Divide numbers into two groups and XOR separately
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if (num & rightmostSetBit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        
        return {num1, num2};
    }
};
// Let's break down how this solution works:

// First XOR Pass:
// XOR all numbers together
// Pairs cancel out (XOR of same number = 0)
// Result is XOR of the two unique numbers (let's call them A and B)
// Finding a Set Bit:
// Get rightmost set bit using n & -n trick
// This bit must be different between A and B (since A ≠ B)
// -n works because in two's complement, it's equivalent to ~n + 1
// Second Pass - Grouping:
// Use the set bit to divide numbers into two groups
// Numbers with this bit set go in group 1
// Numbers with this bit unset go in group 2
// Each group contains one unique number and some pairs
// XOR within each group cancels pairs, leaving the unique numbers
// Example walkthrough for [1,2,1,3,2,5]:

// Step 1: XOR all = 1^2^1^3^2^5 = 3^5 = 6 (binary: 110)
// Step 2: Rightmost set bit = 6 & -6 = 2 (binary: 010)
// Step 3:
// Group 1 (bit 2 set): [2, 2] → 2^2 = 0, then with 3 = 3
// Group 2 (bit 2 unset): [1, 1, 5] → 1^1^5 = 5
// Result: [3, 5]
// Time and Space Complexity:

// Time Complexity: O(n) - two passes through the array
// Space Complexity: O(1) - only uses a few variables
// Key Properties:

// XOR is commutative and associative
// XOR of a number with itself is 0
// XOR of a number with 0 is the number itself
// The solution satisfies all constraints:

// Works for array size 2 to 3 * 10^4
// Handles values from -2^31 to 2^31 - 1
// Finds exactly two numbers that appear once
// Linear runtime with constant space
// Returns answer in any order as allowed
// This is an elegant application of bitwise operations that avoids using extra space like hash maps while maintaining linear time complexity.