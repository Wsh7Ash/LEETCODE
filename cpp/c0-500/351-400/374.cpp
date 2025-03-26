/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *                0 if num is equal to the picked number
 */
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        
        while (left <= right) {
            // Use this to avoid integer overflow instead of (left + right) / 2
            int mid = left + (right - left) / 2;
            
            int result = guess(mid);
            
            if (result == 0) {
                // Found the number
                return mid;
            } else if (result == -1) {
                // Guess is too high, search lower half
                right = mid - 1;
            } else {
                // Guess is too low, search upper half
                left = mid + 1;
            }
        }
        
        // This line should never be reached given the problem constraints
        return -1;
    }
};
This solution uses a binary search approach with the following logic:

Algorithm:
Use two pointers: left (starting at 1) and right (starting at n)
While left <= right:
Calculate mid point
Call guess(mid) to get the hint
If result is 0: we found the number
If result is -1: search lower half
If result is 1: search upper half
Key Features:
Uses left + (right - left) / 2 instead of (left + right) / 2 to prevent integer overflow
Takes advantage of the binary search pattern to efficiently narrow down the search space
Returns immediately when the correct number is found
Time Complexity: O(log n)
Binary search halves the search space in each iteration
At most log₂(n) iterations are needed
Space Complexity: O(1)
Only uses a constant amount of extra space
Example Walkthrough (n = 10, pick = 6):
text

Collapse

Wrap

Copy
left = 1, right = 10
mid = 5, guess(5) = 1 (too low)
left = 6, right = 10
mid = 8, guess(8) = -1 (too high)
left = 6, right = 7
mid = 6, guess(6) = 0 (found)
return 6
Notes:
The solution assumes the guess() API is correctly implemented
Given the constraints (1 <= pick <= n), the while loop will always find the number
The final return -1 is just for completeness and should never be reached
This is an optimal solution because:

It uses binary search to achieve logarithmic time complexity
It handles large values of n (up to 2³¹-1) without overflow
It requires minimal extra space
It's straightforward to understand and implement