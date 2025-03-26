class Solution {
    public:
        int longestPalindrome(string s) {
            // Use array for character counts (covering A-Z and a-z)
            vector<int> count(52, 0);
            
            // Count frequency of each character
            for (char c : s) {
                if (c >= 'a' && c <= 'z') {
                    count[c - 'a']++;
                } else if (c >= 'A' && c <= 'Z') {
                    count[26 + (c - 'A')]++;
                }
            }
            
            int length = 0;
            bool hasOdd = false;
            
            // Process each character count
            for (int freq : count) {
                // Add largest even number of occurrences
                length += (freq / 2) * 2;
                // Check if we have any odd counts
                if (freq % 2 == 1) {
                    hasOdd = true;
                }
            }
            
            // If we have any odd counts, we can add 1 to center
            if (hasOdd) {
                length++;
            }
            
            return length;
        }
    };
    How this solution works:
    
    Approach:
    Count frequency of each character
    Use even counts fully, plus one odd count if available
    Palindrome needs symmetric pairs + optional center
    Key Insight:
    For a palindrome, we need pairs of characters
    We can use all even counts
    If there are any odd counts, we can use one in the middle
    Algorithm:
    Create count array for A-Z (26-51) and a-z (0-25)
    Count frequencies
    For each character:
    Add even portion (freq/2 * 2)
    Track if any odd counts exist
    Add 1 to length if any odd counts found
    Example Walkthrough (s = "abccccdd"):
    text
    
    Collapse
    
    Wrap
    
    Copy
    Counts:
    a:1, b:1, c:4, d:2
    Length calculation:
    - a: 0 (even part)
    - b: 0 (even part)
    - c: 4 (even part)
    - d: 2 (even part)
    Total = 6
    hasOdd = true (from a,b)
    Final = 6 + 1 = 7
    Complexity:
    Time: O(n) where n is string length
    Space: O(1) since count array is fixed size (52)
    Key Features:
    Case sensitive (separates A-Z and a-z)
    Handles single character case
    Maximizes palindrome length
    The solution satisfies all constraints:
    
    Works for s.length from 1 to 2000
    Handles lowercase and uppercase English letters
    Alternative Solution (using unordered_map):
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        int longestPalindrome(string s) {
            unordered_map<char, int> count;
            
            for (char c : s) {
                count[c]++;
            }
            
            int length = 0;
            bool hasOdd = false;
            
            for (auto& [c, freq] : count) {
                length += (freq / 2) * 2;
                if (freq % 2 == 1) {
                    hasOdd = true;
                }
            }
            
            return hasOdd ? length + 1 : length;
        }
    };
    The array-based solution is preferred because:
    
    More space efficient (fixed 52 vs potentially larger map)
    Faster lookups (array vs hash map)
    Same time complexity with better constants
    Both solutions correctly handle:
    
    Example 1: "abccccdd" → 7
    Example 2: "a" → 1
    The solution efficiently computes the longest possible palindrome by:
    
    Using all available pairs of characters
    Adding one odd-count character if possible
    Handling case sensitivity correctly
    This approach is optimal because it processes each character exactly once and uses simple arithmetic to determine the maximum palindrome length possible with the given character frequencies.