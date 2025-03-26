#include <string>

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        int n = s.length();
        if (n <= 1) return false;
        
        // Create string: (s + s) without first and last characters
        std::string doubled = s + s;
        std::string check = doubled.substr(1, 2*n-2);
        
        // If s is a repeated pattern, it will appear in check
        return check.find(s) != std::string::npos;
    }
};
Alternative solution checking possible lengths:

cpp

Collapse

Wrap

Copy
#include <string>

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        int n = s.length();
        if (n <= 1) return false;
        
        // Check all possible substring lengths that divide n
        for (int len = 1; len <= n/2; len++) {
            if (n % len == 0) {  // Length must divide total length evenly
                bool valid = true;
                // Compare characters with first substring
                for (int i = len; i < n; i++) {
                    if (s[i] != s[i % len]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) return true;
            }
        }
        return false;
    }
};
Let's break down how these solutions work:

First Approach (String Concatenation):
Key Insight: If s is "abab", then s+s = "abababab"
Remove first and last char: "bababa"
If s has repeated pattern, it will appear in this string
Time Complexity: O(n) for string operations
Space Complexity: O(n) for new strings
Second Approach (Length Checking):
Check all possible substring lengths up to n/2
For each length that divides n evenly:
Verify if string can be built by repeating that substring
Time Complexity: O(n²) in worst case
Space Complexity: O(1)
Example walkthrough (first approach):

Example 1: s = "abab"

doubled = "abababab"
check = "bababa"
s "abab" exists in "bababa" at position 2
Result: true
Example 2: s = "aba"

doubled = "abaaba"
check = "baab"
s "aba" not found in "baab"
Result: false
Example 3: s = "abcabcabcabc"

doubled = "abcabcabcabcabcabcabcabc"
check = "bcabcabcabcabcabcabcab"
s "abcabcabcabc" found in check
Result: true
The first solution handles all constraints:

Works for 1 <= s.length <= 10⁴
Works with lowercase English letters
Correctly identifies repeated patterns
Why the first approach works:

If s is made of k repeated patterns (k > 1)
s + s will contain at least 2k patterns
Removing first and last chars leaves at least k patterns
Original s will always be found in middle if it's repeating
If s isn't repeating, it won't appear as a substring