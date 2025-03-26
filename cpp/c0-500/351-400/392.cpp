class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int sIndex = 0;  // Pointer for string s
            
            // If s is empty, it's always a subsequence
            if (s.empty()) return true;
            
            // Scan through t
            for (char c : t) {
                if (c == s[sIndex]) {
                    sIndex++;
                    // If we've matched all characters in s
                    if (sIndex == s.length()) return true;
                }
            }
            
            // If we haven't matched all characters in s
            return false;
        }
    };
    Solution 2 - Index Checking Approach:
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int tIndex = -1;  // Last found position in t
            
            // Check each character of s
            for (char c : s) {
                // Find next occurrence after previous position
                tIndex = t.find(c, tIndex + 1);
                if (tIndex == string::npos) {
                    return false;  // Character not found
                }
            }
            
            return true;
        }
    };
    Let's break down these solutions:
    
    Two Pointer Approach:
    How it works:
    Uses one pointer for s
    Scans t sequentially
    Advances s pointer when match found
    Returns true if all s characters matched
    Time Complexity: O(n) where n is length of t
    Space Complexity: O(1)
    Example: s="abc", t="ahbgdc"
    text
    
    Collapse
    
    Wrap
    
    Copy
    t: a h b g d c
    s: a   b     c
    Returns true
    Index Checking Approach:
    How it works:
    Uses string::find to locate each character
    Ensures characters appear in order
    Tracks last found position
    Time Complexity: O(n*m) where n is length of s, m is length of t
    Space Complexity: O(1)
    Example: s="axc", t="ahbgdc"
    text
    
    Collapse
    
    Wrap
    
    Copy
    a found at 0
    x not found after 0
    Returns false
    Key Points:
    
    Both solutions handle empty string cases
    Both work with lowercase English letters
    Two Pointer is more efficient for single check
    Index Checking could be modified for multiple subsequence checks
    The Two Pointer approach is generally preferred because:
    
    Better time complexity (O(n) vs O(n*m))
    Simpler implementation
    No reliance on string library functions
    More intuitive for this specific problem
    Both solutions satisfy all constraints:
    
    Handle s.length from 0 to 100
    Handle t.length from 0 to 10^4
    Work with lowercase English letters
    For the example cases:
    
    "abc" in "ahbgdc" → true
    "axc" in "ahbgdc" → false
    If you needed to check multiple subsequences against the same t string, you could preprocess t into a character position map for O(m + k) time complexity (where m is length of t and k is total length of all s strings to check), but that's not required for this specific problem.