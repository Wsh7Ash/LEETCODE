#include <string>

class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        
        int count = 0;
        bool inSegment = false;
        
        for (char c : s) {
            if (c == ' ') {
                inSegment = false;
            } else if (!inSegment) {
                inSegment = true;
                count++;
            }
        }
        
        return count;
    }
};
Alternative solution using a simpler approach:

cpp

Collapse

Wrap

Copy
#include <string>

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            // If current char is non-space and either it's first char or previous char was space
            if (s[i] != ' ' && (i == 0 || s[i-1] == ' ')) {
                count++;
            }
        }
        return count;
    }
};
Let's break down how these solutions work:

First Solution (State Machine Approach):
Uses a boolean flag inSegment to track if we're currently in a segment
When we hit a space, reset the flag
When we hit a non-space and weren't in a segment, increment count and set flag
Time Complexity: O(n) where n is string length
Space Complexity: O(1)
Second Solution (Direct Approach):
Counts a new segment when:
Current character is non-space AND
Either it's the first character OR previous character was a space
Time Complexity: O(n) where n is string length
Space Complexity: O(1)
Example 1: "Hello, my name is John"
Second solution:
"H" (i=0, non-space) → count=1
"," (prev='o') → no count
"m" (prev=' ') → count=2
"n" (prev=' ') → count=3
"i" (prev=' ') → count=4
"J" (prev=' ') → count=5
Output: 5
Example 2: "Hello"
"H" (i=0, non-space) → count=1
Rest are continuations of same segment
Output: 1
Edge Cases Handled:
Empty string → returns 0
Single word → returns 1
Multiple spaces between words → counts correctly
Leading/trailing spaces → counts correctly
Constraints Satisfied:
Works for strings 0 ≤ length ≤ 300
Handles all specified characters
Correctly processes single space character ' '
Both solutions are correct and efficient. The second solution might be slightly more intuitive as it directly checks for segment starts without maintaining a state variable. Choose based on your preference for readability vs. explicit state tracking.