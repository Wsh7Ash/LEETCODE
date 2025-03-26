#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(string s, int k) {
        // Array to store count of each character (A-Z)
        vector<int> count(26, 0);
        int maxCount = 0;  // Count of most frequent character in current window
        int maxLength = 0; // Length of longest valid substring
        int left = 0;      // Left pointer of sliding window
        
        // Iterate through string with right pointer
        for (int right = 0; right < s.length(); right++) {
            // Increment count of current character
            count[s[right] - 'A']++;
            // Update maxCount if current character count exceeds previous max
            maxCount = max(maxCount, count[s[right] - 'A']);
            
            // Window size is (right - left + 1)
            // Number of characters to replace = window size - count of most frequent char
            // If we need to replace more than k characters, shrink window from left
            while (right - left + 1 - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            // Update maxLength if current window is longer
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
Let's break down how this solution works:

Key Insight:
For any window, we can make all characters the same by replacing all other characters with the most frequent character
Window is valid if: (window length - count of most frequent char) ≤ k
We don't need to actually replace characters, just check if it's possible
Algorithm:
Use sliding window with two pointers (left and right)
Maintain count of each character in current window
Track maxCount (count of most frequent character in window)
If window becomes invalid (> k replacements needed), shrink from left
Keep track of maximum valid window length
Step-by-step:
Move right pointer, adding new character to count
Update maxCount
Check if window is valid
If invalid, move left pointer until valid
Update maxLength
Example 1: "ABAB", k=2
Window "ABAB": length=4, maxCount=2 (A or B), replacements=2 ≤ k
Result: 4
Example 2: "AABABBA", k=1
Window "AABA": length=4, maxCount=3 (A), replacements=1 ≤ k
Result: 4
Time and Space Complexity:
Time Complexity: O(n) where n is length of string
Space Complexity: O(1) since count array is fixed size (26)
The solution efficiently handles all constraints:

Works for string lengths from 1 to 10^5
Handles only uppercase English letters
Works for k from 0 to string length
Returns the maximum possible length of repeating characters after at most k replacements