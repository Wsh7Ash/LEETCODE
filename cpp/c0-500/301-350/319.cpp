The problem involves simulating the toggling of bulbs over n rounds and determining how many bulbs remain on at the end. However, simulating each round explicitly for large n (up to 
    1
    0
    9
    10 
    9
     ) is computationally infeasible. Instead, we can use a mathematical approach to solve the problem efficiently.
    
    Key Insight:
    Toggling Pattern:
    
    A bulb is toggled once for every one of its divisors. For example, bulb 6 is toggled in rounds 1, 2, 3, and 6.
    
    If a bulb has an odd number of divisors, it will end up being on. Otherwise, it will be off.
    
    Perfect Squares:
    
    Only perfect squares have an odd number of divisors because divisors come in pairs, except for the square root (which is counted once).
    
    For example, bulb 9 has divisors 1, 3, and 9 (odd number of divisors).
    
    Result:
    
    The number of bulbs that remain on is equal to the number of perfect squares less than or equal to n.
    
    Solution:
    The number of perfect squares less than or equal to n is simply the integer part of the square root of n, i.e., 
    ⌊
    n
    ⌋
    ⌊ 
    n
    ​
     ⌋.
    
    Code Implementation:
    cpp
    Copy
    #include <cmath>
    
    class Solution {
    public:
        int bulbSwitch(int n) {
            // The number of bulbs that remain on is the integer part of the square root of n
            return static_cast<int>(std::sqrt(n));
        }
    };
    Explanation:
    Mathematical Insight:
    
    The problem reduces to finding the number of perfect squares ≤ n.
    
    For example:
    
    If n = 3, the perfect squares ≤ 3 are 1 (1²). So, the result is 1.
    
    If n = 10, the perfect squares ≤ 10 are 1 (1²), 4 (2²), and 9 (3²). So, the result is 3.
    
    Efficiency:
    
    The solution computes the square root of n in constant time, making it extremely efficient even for large values of n (up to 
    1
    0
    9
    10 
    9
     ).
    
    Example Walkthrough:
    Input: n = 3
    Compute 
    3
    ≈
    1.732
    3
    ​
     ≈1.732.
    
    The integer part is 1.
    
    Result: 1.
    
    Input: n = 10
    Compute 
    10
    ≈
    3.162
    10
    ​
     ≈3.162.
    
    The integer part is 3.
    
    Result: 3.
    
    Input: n = 0
    Compute 
    0
    =
    0
    0
    ​
     =0.
    
    The integer part is 0.
    
    Result: 0.
    
    Time Complexity:
    O(1): The solution involves a single square root computation, which is constant time.
    
    Space Complexity:
    O(1): No additional space is used.
    
    This approach is optimal and works efficiently for the given constraints.