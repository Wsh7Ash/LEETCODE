class Solution {
    public boolean isPerfectSquare(int num) {
        if (num == 1) return true;  // Special case
        
        long left = 1;
        long right = num / 2;
        
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long square = mid * mid;
            
            if (square == num) {
                return true;
            } else if (square < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
}
Let's break down how this works:

Approach:
Use binary search to find a number whose square equals num
Search space is from 1 to num/2 (since sqrt(num) can't be more than num/2)
Use long to avoid integer overflow
Algorithm:
Handle special case of 1 separately
Set initial bounds: left=1, right=num/2
Binary search:
Calculate mid point
Compute square (using long to prevent overflow)
If square matches num, return true
If square < num, search right half
If square > num, search left half
If no match found, return false
Example Walkthrough:
text
Wrap
Copy
num = 16:
left=1, right=8
mid=4, 4*4=16 ✓
return true

num = 14:
left=1, right=7
mid=4, 16 > 14, right=3
mid=2, 4 < 14, left=3
mid=3, 9 < 14, left=4
left > right, return false
Time Complexity: O(log n) - binary search
Space Complexity: O(1)
Key Points:
Uses long to handle large numbers (up to 2³¹-1)
Avoids overflow by using long for multiplication
Doesn't use sqrt as required
Handles edge case of 1
Correctness:
If num is perfect square, binary search will find exact match
If not perfect square, no integer will satisfy condition
Search space is complete (1 to num/2 covers all possibilities)
The solution meets all constraints:

Works for 1 ≤ num ≤ 2³¹-1
Correctly identifies perfect squares
Doesn't use built-in sqrt function
Returns boolean as required
This binary search approach is efficient and meets the requirement of not using built-in square root functions. It's more efficient than checking all numbers from 1 to num sequentially (which would be O(n)).