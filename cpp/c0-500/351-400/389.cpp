class Solution {
    public:
        char findTheDifference(string s, string t) {
            char result = 0;
            
            // XOR all characters in s
            for (char c : s) {
                result ^= c;
            }
            
            // XOR all characters in t
            for (char c : t) {
                result ^= c;
            }
            
            return result;
        }
    };
    Solution 2 - Using Sum Difference:
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        char findTheDifference(string s, string t) {
            int sumS = 0;
            int sumT = 0;
            
            // Calculate sum of character values in s
            for (char c : s) {
                sumS += c;
            }
            
            // Calculate sum of character values in t
            for (char c : t) {
                sumT += c;
            }
            
            // Difference gives us the added character
            return static_cast<char>(sumT - sumS);
        }
    };
    Let's break down both solutions:
    
    XOR Solution:
    How it works:
    XOR of a number with itself is 0
    XOR of a number with 0 is the number itself
    When we XOR all characters from both strings, all matching characters cancel out
    The remaining value is the added character
    Time Complexity: O(n) where n is length of string s
    Space Complexity: O(1)
    Example: "abcd" vs "abcde"
    text
    
    Collapse
    
    Wrap
    
    Copy
    a^b^c^d^a^b^c^d^e = e
    (all pairs cancel out, leaving only e)
    Sum Difference Solution:
    How it works:
    Sum ASCII values of all characters in both strings
    The difference between sums is the ASCII value of the added character
    Time Complexity: O(n)
    Space Complexity: O(1)
    Example: "abcd" vs "abcde"
    text
    
    Collapse
    
    Wrap
    
    Copy
    sumS = 97+98+99+100 = 394
    sumT = 97+98+99+100+101 = 495
    495 - 394 = 101 ('e')
    Both solutions satisfy all constraints:
    
    Work with s.length from 0 to 1000
    Handle t.length = s.length + 1
    Work with lowercase English letters
    Return a single character
    Key advantages:
    
    XOR Solution: More elegant, uses bitwise operations
    Sum Solution: More intuitive, easier to understand
    The XOR solution is slightly more efficient as it:
    
    Uses a single variable instead of two
    Can be written in a single loop combining both strings
    Doesn't risk integer overflow with very long strings
    Here's an even more optimized XOR version:
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        char findTheDifference(string s, string t) {
            char result = t[s.length()];  // Last character of t
            for (int i = 0; i < s.length(); i++) {
                result ^= s[i] ^ t[i];
            }
            return result;
        }
    };
    All these solutions correctly handle the example cases:
    
    "abcd" vs "abcde" → "e"
    "" vs "y" → "y"