// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
    public:
        int rand10() {
            while (true) {
                // Generate a number from 0-48 (7x7 grid)
                int row = rand7() - 1;    // 0-6
                int col = rand7() - 1;    // 0-6
                int idx = row * 7 + col;  // 0-48
                
                // Reject numbers >= 40 to get uniform distribution from 0-39
                if (idx >= 40) {
                    continue;
                }
                
                // Map 0-39 to 1-10
                return (idx % 10) + 1;
            }
        }
    };
    Let's break down how this solution works:
    
    Key Concept:
    We need to generate 10 equally likely outcomes using only 7 equally likely outcomes
    We can combine two rand7() calls to create a larger range, then map it to 1-10
    Algorithm Explanation:
    Call rand7() twice to create a 7x7 grid (49 possible outcomes: 0-48)
    Use only 40 of these outcomes (0-39) and reject the rest
    Map 0-39 to 1-10 by using modulo 10 and adding 1
    Step-by-Step:
    rand7() - 1 gives us 0-6
    First call (row) * 7 + second call (col) gives us 0-48
    Reject if ≥ 40 (keeps 40 numbers: 0-39)
    idx % 10 + 1 maps to 1-10 (each number appears exactly 4 times)
    Why It’s Uniform:
    Each of the 49 combinations has equal probability (1/49)
    We accept 40 of them (probability of acceptance = 40/49)
    Each number 1-10 appears exactly 4 times in 0-39
    Probability of each number = 4/40 = 1/10
    Time Complexity:
    Expected number of iterations = 49/40 ≈ 1.225
    Expected Time: O(1)
    Worst case: unbounded (but very unlikely)
    Space Complexity: O(1)
    Example:
    Say rand7() returns 3, then 5:
    idx = (3-1)7 + (5-1) = 27 + 4 = 18
    18 < 40 (accept)
    18 % 10 + 1 = 9
    Returns 9
    Verification:
    Numbers 0-39 map as follows:
    0-9: 1-10
    10-19: 1-10
    20-29: 1-10
    30-39: 1-10
    Each number appears 4 times, ensuring uniformity
    This solution satisfies all requirements:
    
    Uses only rand7()
    Generates uniform random numbers 1-10
    Works for any number of calls (n)
    Doesn't use any built-in random API