class Solution {
    public:
        int getSum(int a, int b) {
            while (b != 0) {
                // Carry is calculated using AND and left shift
                unsigned int carry = (unsigned int)(a & b) << 1;
                // Sum without carry using XOR
                a = a ^ b;
                // Update b to handle carry in next iteration
                b = carry;
            }
            return a;
        }
    };
    Let's break down how this works:
    
    Key Concept:
    We can add numbers using bitwise operations:
    XOR (^) gives sum without carry
    AND (&) with left shift gives carry
    Repeat until no carry remains
    Algorithm:
    While there's still a carry (b != 0):
    Calculate carry: (a & b) << 1
    Calculate sum without carry: a ^ b
    Update a with sum, b with carry
    Return final result when carry becomes 0
    Why Unsigned Int for Carry:
    Prevents sign extension issues during left shift
    Handles negative numbers correctly
    Example Walkthrough:
    text
    Wrap
    Copy
    a = 1 (0001), b = 2 (0010)
    First iteration:
    - carry = (0001 & 0010) << 1 = 0000 << 1 = 0
    - a = 0001 ^ 0010 = 0011 (3)
    - b = 0
    b = 0, return 3
    
    a = 3 (0011), b = 5 (0101)
    First iteration:
    - carry = (0011 & 0101) << 1 = 0001 << 1 = 0010
    - a = 0011 ^ 0101 = 0110 (6)
    - b = 0010 (2)
    Second iteration:
    - carry = (0110 & 0010) << 1 = 0010 << 1 = 0100
    - a = 0110 ^ 0010 = 0100 (4)
    - b = 0100 (4)
    Third iteration:
    - carry = (0100 & 0100) << 1 = 0100 << 1 = 1000
    - a = 0100 ^ 0100 = 0000 (0)
    - b = 1000 (8)
    Fourth iteration:
    - carry = (0000 & 1000) << 1 = 0
    - a = 0000 ^ 1000 = 1000 (8)
    - b = 0
    Return 8
    How It Handles Negative Numbers:
    text
    Wrap
    Copy
    a = -2 (1110), b = 1 (0001)
    First iteration:
    - carry = (1110 & 0001) << 1 = 0
    - a = 1110 ^ 0001 = 1111 (-1)
    - b = 0
    Return -1
    Time Complexity: O(log n) where n is max number of bits needed
    Space Complexity: O(1)
    The solution meets all constraints:
    
    Works for -1000 ≤ a,b ≤ 1000
    Doesn't use + or - operators
    Correctly handles positive and negative integers
    This bitwise approach simulates addition by:
    
    Using XOR for digit-by-digit addition without carry
    Using AND with shift for carry propagation
    Iterating until all carries are processed
    The use of unsigned int for carry is crucial to handle the left shift correctly when dealing with negative numbers in two's complement representation.