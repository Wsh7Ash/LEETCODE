To solve the Number of Digit One problem, we need to count the total number of digit 1 appearing in all non-negative integers less than or equal to n. This problem requires a mathematical approach to efficiently compute the result without iterating through all numbers up to n.

Approach:
Digit by Digit Analysis:

For each digit position (units, tens, hundreds, etc.), calculate the number of times the digit 1 appears at that position across all numbers from 0 to n.

Mathematical Formula:

For a given digit position d (where d is the power of 10, e.g., 1, 10, 100, etc.):

The number of times 1 appears at position d is determined by:

The number of complete cycles of 10 * d in n.

The remainder of n modulo 10 * d, which determines how many additional 1s appear in the current incomplete cycle.

General Formula:

For a digit position d, the number of 1s at that position is:

count
=
⌊
n
10
⋅
d
⌋
⋅
d
+
min
⁡
(
max
⁡
(
n
 
mod
 
(
10
⋅
d
)
−
d
+
1
,
0
)
,
d
)
count=⌊ 
10⋅d
n
​
 ⌋⋅d+min(max(nmod(10⋅d)−d+1,0),d)
Here:

⌊
n
10
⋅
d
⌋
⋅
d
⌊ 
10⋅d
n
​
 ⌋⋅d counts the number of complete cycles.

min
⁡
(
max
⁡
(
n
 
mod
 
(
10
⋅
d
)
−
d
+
1
,
0
)
,
d
)
min(max(nmod(10⋅d)−d+1,0),d) counts the additional 1s in the current incomplete cycle.

Iterate Over All Digit Positions:

Iterate over all digit positions (from 1 to the highest power of 10 less than or equal to n).

Sum the counts of 1s at each position to get the total number of 1s.

Solution Code:
cpp
Copy
class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for (long d = 1; d <= n; d *= 10) {
            long divisor = d * 10;
            // Number of complete cycles
            count += (n / divisor) * d;
            // Additional 1s in the current incomplete cycle
            count += min(max(n % divisor - d + 1, 0L), d);
        }
        return count;
    }
};
Explanation:
Complete Cycles:

For each digit position d, the number of complete cycles of 10 * d in n is given by 
⌊
n
10
⋅
d
⌋
⋅
d
⌊ 
10⋅d
n
​
 ⌋⋅d. This counts the number of times 1 appears at position d in all complete cycles.

Incomplete Cycle:

The remainder of n modulo 10 * d determines how many additional 1s appear in the current incomplete cycle.

The formula 
min
⁡
(
max
⁡
(
n
 
mod
 
(
10
⋅
d
)
−
d
+
1
,
0
)
,
d
)
min(max(nmod(10⋅d)−d+1,0),d) ensures that we count only valid 1s in the current cycle.

Iteration:

We iterate over all digit positions (from 1 to the highest power of 10 less than or equal to n).

For each position, we compute the number of 1s and add it to the total count.

Example Walkthrough:
Example 1:
Input: n = 13

Output: 6

Execution:
Digit Position 1 (Units Place):

Complete cycles: 
⌊
13
10
⌋
⋅
1
=
1
⋅
1
=
1
⌊ 
10
13
​
 ⌋⋅1=1⋅1=1

Incomplete cycle: 
min
⁡
(
max
⁡
(
13
 
mod
 
10
−
1
+
1
,
0
)
,
1
)
=
min
⁡
(
max
⁡
(
3
,
0
)
,
1
)
=
1
min(max(13mod10−1+1,0),1)=min(max(3,0),1)=1

Total 1s at units place: 
1
+
1
=
2
1+1=2

Digit Position 10 (Tens Place):

Complete cycles: 
⌊
13
100
⌋
⋅
10
=
0
⋅
10
=
0
⌊ 
100
13
​
 ⌋⋅10=0⋅10=0

Incomplete cycle: 
min
⁡
(
max
⁡
(
13
 
mod
 
100
−
10
+
1
,
0
)
,
10
)
=
min
⁡
(
max
⁡
(
13
−
10
+
1
,
0
)
,
10
)
=
min
⁡
(
4
,
10
)
=
4
min(max(13mod100−10+1,0),10)=min(max(13−10+1,0),10)=min(4,10)=4

Total 1s at tens place: 
0
+
4
=
4
0+4=4

Total 1s:

2
+
4
=
6
2+4=6

Example 2:
Input: n = 0

Output: 0

Execution:
No 1s are present in the range [0, 0].

Key Points:
The solution uses a mathematical approach to count 1s efficiently without iterating through all numbers.

The time complexity is 
O
(
log
⁡
10
n
)
O(log 
10
​
 n), as we iterate over each digit position.

The space complexity is 
O
(
1
)
O(1), as we use only a few variables.

