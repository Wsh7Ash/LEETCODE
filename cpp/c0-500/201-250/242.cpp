#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // If lengths are different, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        
        // Create an array to store character frequencies (26 lowercase letters)
        int charCount[26] = {0};
        
        // Count frequencies in first string
        for (char c : s) {
            charCount[c - 'a']++;
        }
        
        // Decrease frequencies for second string
        for (char c : t) {
            charCount[c - 'a']--;
        }
        
        // Check if all frequencies are zero
        for (int count : charCount) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }
};
// Let's break down how this solution works:

// Initial Length Check:
// If the strings have different lengths, they can't be anagrams
// This quick check saves time for obvious non-anagram cases
// Frequency Counting:
// We use an array of size 26 (for lowercase English letters a-z)
// Initialize all counts to 0
// For string s: increment count for each character
// For string t: decrement count for each character
// Verification:
// If strings are anagrams, all counts should return to 0
// If any count is non-zero, they aren't anagrams
// Time and Space Complexity:
// Time Complexity: O(n), where n is the length of the strings
// Space Complexity: O(1), since we use a fixed-size array of 26 elements
// Example walkthrough:

// For s = "anagram", t = "nagaram":
// Length check: both are 7, proceed
// After counting s: [a:3, n:1, g:1, r:1, m:1]
// After counting t: [a:0, n:0, g:0, r:0, m:0]
// All counts are 0, return true
// For s = "rat", t = "car":
// Length check: both are 3, proceed
// After counting s: [r:1, a:1, t:1]
// After counting t: [r:0, a:0, t:1, c:-1]
// Some counts are non-zero, return false
// Alternative Approach:
// You could also sort both strings and compare them, but that would take O(n log n) time. The frequency counting method is more efficient at O(n).

// The solution satisfies all constraints:

// Works for strings of length 1 to 5 * 10^4
// Handles lowercase English letters only
// Returns correct boolean result