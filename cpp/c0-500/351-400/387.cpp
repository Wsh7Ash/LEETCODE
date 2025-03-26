#include <string>
#include <unordered_map>

class Solution {
public:
    int firstUniqChar(string s) {
        // Create a hash map to store character frequencies
        unordered_map<char, int> charCount;
        
        // Count frequency of each character
        for (char c : s) {
            charCount[c]++;
        }
        
        // Find first character with frequency of 1
        for (int i = 0; i < s.length(); i++) {
            if (charCount[s[i]] == 1) {
                return i;
            }
        }
        
        // No unique character found
        return -1;
    }
};
Let's break down how this solution works:

Approach:
We use a hash map to store the frequency of each character
Then we iterate through the string again to find the first character with frequency 1
Time Complexity: O(n) where n is the length of the string
Space Complexity: O(k) where k is the size of the character set (26 lowercase letters in this case)
Step-by-step explanation:
First loop: Count how many times each character appears
Second loop: Check each character's frequency using the map
Return the index of first character with frequency 1
Return -1 if no such character exists
Example walkthrough: For s = "loveleetcode":
text

Collapse

Wrap

Copy
First pass (frequency count):
l:2, o:2, v:1, e:3, t:1, c:1

Second pass (checking string positions):
l (index 0): freq=2 → not unique
o (index 1): freq=2 → not unique
v (index 2): freq=1 → return 2
Alternative solution using array (since we only have lowercase letters):

cpp

Collapse

Wrap

Copy
class Solution {
public:
    int firstUniqChar(string s) {
        // Array for 26 lowercase letters
        int charCount[26] = {0};
        
        // Count frequency
        for (char c : s) {
            charCount[c - 'a']++;
        }
        
        // Find first unique
        for (int i = 0; i < s.length(); i++) {
            if (charCount[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};
This array-based solution is more space-efficient as it uses a fixed-size array of 26 instead of a hash map. Both solutions meet all the constraints:

Works for strings of length 1 to 10^5
Handles only lowercase English letters
Returns correct index or -1 when no unique character exists
The array solution might be slightly faster in practice due to better cache locality and no hash function overhead, though both have the same O(n) time complexity.