To determine if an integer n is a power of two, we can use the following properties of powers of two:

Binary Representation:

A power of two in binary has exactly one 1 followed by zeros. For example:

2
0
=
1
2 
0
 =1 → 1

2
1
=
2
2 
1
 =2 → 10

2
2
=
4
2 
2
 =4 → 100

2
3
=
8
2 
3
 =8 → 1000

Bitwise Operation:

If n is a power of two, then n & (n - 1) will be 0. For example:

8
=
1000
8=1000, 
7
=
0111
7=0111 → 
8
&
7
=
0
8&7=0

Additionally, n must be greater than 0 because 
2
x
2 
x
  is always positive.

Approach:
Check if n is Positive:

If n <= 0, it cannot be a power of two.

Use Bitwise Operation:

Compute n & (n - 1) and check if the result is 0.

Return Result:

If both conditions are satisfied, return true; otherwise, return false.

Solution Code:
cpp
Copy
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A power of two must be greater than 0
        if (n <= 0) {
            return false;
        }
        // Check if n has exactly one '1' in its binary representation
        return (n & (n - 1)) == 0;
    }
};
Explanation:
Check if n is Positive:

Powers of two are always positive, so if n <= 0, we immediately return false.

Bitwise Operation:

For a number n that is a power of two, the binary representation has exactly one 1. Subtracting 1 from n flips all the bits after the single 1 to 1, and the 1 itself to 0. For example:

8
=
1000
8=1000, 
7
=
0111
7=0111 → 
8
&
7
=
0000
8&7=0000

If n & (n - 1) is 0, then n is a power of two.

Efficiency:

The solution runs in 
O
(
1
)
O(1) time because it involves a constant number of operations.

Example Walkthrough:
Example 1:
Input: n = 1

Binary: 1

1
&
(
1
−
1
)
=
1
&
0
=
0
1&(1−1)=1&0=0

Output: true

Example 2:
Input: n = 16

Binary: 10000

16
&
(
16
−
1
)
=
10000
&
01111
=
0
16&(16−1)=10000&01111=0

Output: true

Example 3:
Input: n = 3

Binary: 11

3
&
(
3
−
1
)
=
11
&
10
=
10
≠
0
3&(3−1)=11&10=10

=0

Output: false

Key Points:
The solution leverages the binary representation of numbers and bitwise operations.

It is efficient and works in constant time 
O
(
1
)
O(1).

The edge case of n <= 0 is handled explicitly.