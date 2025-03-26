class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            // Array to store frequency of each lowercase letter (26 letters)
            int charCount[26] = {0};
            
            // Count frequency of each character in magazine
            for (char c : magazine) {
                charCount[c - 'a']++;
            }
            
            // Check if we have enough characters for ransomNote
            for (char c : ransomNote) {
                if (charCount[c - 'a'] == 0) {
                    return false;  // Not enough of this character
                }
                charCount[c - 'a']--;
            }
            
            return true;
        }
    };
    Let's break down how this solution works:
    
    Approach:
    Use an array of size 26 to count frequency of each lowercase letter
    First count all available letters in magazine
    Then subtract required letters for ransomNote
    If at any point we need a letter that's not available, return false
    Implementation Details:
    int charCount[26] = {0} initializes array with zeros
    c - 'a' converts char to array index (0-25)
    'a' becomes 0, 'b' becomes 1, etc.
    First loop increments counts for available letters
    Second loop decrements counts for required letters
    Time and Space Complexity:
    Time Complexity: O(m + n)
    where m is length of magazine
    where n is length of ransomNote
    Space Complexity: O(1)
    Fixed size array of 26 elements regardless of input size
    Example Walkthrough:
    text
    
    Collapse
    
    Wrap
    
    Copy
    ransomNote = "aa", magazine = "aab"
    Step 1: Count magazine letters
    charCount: [a:2, b:1, c:0, ...]
    
    Step 2: Check ransomNote
    First 'a': charCount[a] = 2 -> 1 (still >= 0)
    Second 'a': charCount[a] = 1 -> 0 (still >= 0)
    All characters found -> return true
    Why it works:
    Each letter in magazine can only be used once (handled by decrementing)
    If we ever need a letter that's not available (count = 0), we return false
    If we can process entire ransomNote, all required letters were available
    The solution meets all constraints:
    
    Works for strings of length 1 to 10^5
    Handles lowercase English letters only
    Correctly implements the "use once" requirement
    This is an efficient solution that uses minimal extra space and processes each character exactly once.