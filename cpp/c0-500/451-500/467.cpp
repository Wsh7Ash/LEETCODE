#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        if (s.empty()) return 0;
        
        // Array to store the maximum length of contiguous substring ending with each letter
        vector<int> maxLength(26, 0);
        
        // Keep track of current contiguous sequence length
        int currLength = 0;
        
        // Process each character in the string
        for (int i = 0; i < s.length(); i++) {
            // Check if current character continues the previous sequence
            if (i > 0 && (s[i] - s[i-1] - 1) % 26 == 0) {
                currLength++;
            } else {
                currLength = 1;
            }
            
            // Update maximum length for current ending character
            int index = s[i] - 'a';
            maxLength[index] = max(maxLength[index], currLength);
        }
        
        // Sum up all maximum lengths to get total unique substrings
        int total = 0;
        for (int len : maxLength) {
            total += len;
        }
        
        return total;
    }
};
Let's break down how this solution works:

Key Insight:
We don't need to generate all possible substrings
For each character, we only need to track the longest contiguous sequence ending with that character
Any shorter sequence ending with the same character would be a substring of the longest one
The wraparound property means 'z' can be followed by 'a'
Algorithm Approach:
Use an array of size 26 to store max length of contiguous substring ending at each letter
Process string character by character
Track current contiguous sequence length
Update max length for each ending character
Implementation Details:
(s[i] - s[i-1] - 1) % 26 == 0 checks if characters are consecutive
Subtracting 1 handles the normal case (b follows a)
Modulo 26 handles the wraparound case (a follows z)
For each position, update maxLength only if current length is greater
Sum all max lengths for final answer
Time and Space Complexity:
Time Complexity: O(n) where n is length of string
Space Complexity: O(1) since we use a fixed-size array of 26
Example Walkthrough (s = "zab"):
i=0: 'z', currLength=1, maxLength['z'-'a']=1
i=1: 'a', (a-z-1)%26=0, currLength=2, maxLength['a'-'a']=2
i=2: 'b', (b-a-1)%26=0, currLength=3, maxLength['b'-'a']=3
Total = 1 + 2 + 3 = 6
Why It Works:
For "zab":
Ending with 'z': "z" (length 1)
Ending with 'a': "za", "a" (max length 2)
Ending with 'b': "zab", "ab", "b" (max length 3)
All unique substrings are counted exactly once
Duplicates are automatically handled by keeping only max length