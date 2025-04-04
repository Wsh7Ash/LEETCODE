For "Ugly Number II", we need to find the nth ugly number where ugly numbers are positive integers whose prime factors are only 2, 3, and 5. A common efficient approach is to use a dynamic programming solution with multiple pointers.

Here's a C++ solution:

cpp
Wrap
Copy
class Solution {
public:
    long long nthUglyNumber(int n) {
        // Vector to store ugly numbers
        vector<long long> ugly(n);
        ugly[0] = 1;  // First ugly number is 1
        
        // Three pointers for multiples of 2, 3, and 5
        int i2 = 0, i3 = 0, i5 = 0;
        
        // Next multiples to be considered
        long long next2 = 2;
        long long next3 = 3;
        long long next5 = 5;
        
        // Generate ugly numbers
        for (int i = 1; i < n; i++) {
            // Take the minimum of the next possible ugly numbers
            long long next_ugly = min(next2, min(next3, next5));
            ugly[i] = next_ugly;
            
            // Update the pointers and next multiples
            if (next_ugly == next2) {
                i2++;
                next2 = ugly[i2] * 2;
            }
            if (next_ugly == next3) {
                i3++;
                next3 = ugly[i3] * 3;
            }
            if (next_ugly == next5) {
                i5++;
                next5 = ugly[i5] * 5;
            }
        }
        
        return ugly[n-1];
    }
};
How it works:

Concept:
Every ugly number is generated by multiplying previous ugly numbers by 2, 3, or 5
We maintain three pointers (i2, i3, i5) to track which ugly number to multiply next
We always take the smallest next possible ugly number
Algorithm:
Start with 1 as the first ugly number
For each position:
Calculate next possible numbers (current ugly × 2, × 3, × 5)
Take the minimum as the next ugly number
Increment the pointer(s) for whichever factor(s) we used
Update the next multiples accordingly
Key Points:
Use long long to handle large numbers (constraint up to 1690th ugly number)
Multiple if statements instead of else if because a number might be reached by multiple paths (e.g., 6 = 2×3 = 3×2)
Vector size is n, and we return the (n-1)th index
Time Complexity: O(n) - We generate each ugly number once
Space Complexity: O(n) - We store n ugly numbers

Example:
For n = 10:

ugly[0] = 1
ugly[1] = min(2,3,5) = 2
ugly[2] = min(4,3,5) = 3
ugly[3] = min(4,6,5) = 4
ugly[4] = min(6,6,5) = 5
ugly[5] = min(6,6,10) = 6
ugly[6] = min(8,9,10) = 8
ugly[7] = min(10,9,10) = 9
ugly[8] = min(10,12,10) = 10
ugly[9] = min(12,12,15) = 12
Output: 12 (10th ugly number)

The solution handles all constraints (1 ≤ n ≤ 1690) and produces the correct sequence of ugly numbers: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12, ...].