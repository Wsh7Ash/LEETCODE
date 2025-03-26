#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.length();
        int len2 = s2.length();
        
        // If s1 is too short or n1 is 0, return 0
        if (len1 * n1 < len2 * n2) return 0;
        
        // For each position in s2, store how many s1 chars we need to match it
        vector<int> repeatCount(len2 + 1, 0);
        vector<int> nextIndex(len2 + 1, 0);
        
        int j = 0;  // position in s2
        int count = 0;  // number of s2 completed
        
        // Process one s1 at a time
        for (int k = 0; k < n1; k++) {
            for (int i = 0; i < len1; i++) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == len2) {
                        j = 0;
                        count++;
                    }
                }
            }
            
            // Check for pattern repetition
            if (k == 0) {
                repeatCount[j] = count;
                nextIndex[j] = k + 1;
            } else if (j != 0 && repeatCount[j] == count - 1) {
                // Found a cycle
                int cycleLen = k + 1 - nextIndex[j];
                int cycleCount = count - repeatCount[j];
                
                // Calculate how many complete cycles we can have
                int cycles = (n1 - nextIndex[j]) / cycleLen;
                int totalCount = repeatCount[j] + cycles * cycleCount;
                
                // Process remaining s1 strings after complete cycles
                int remaining = (n1 - nextIndex[j]) % cycleLen;
                for (int m = 0; m < remaining; m++) {
                    for (int i = 0; i < len1; i++) {
                        if (s1[i] == s2[j]) {
                            j++;
                            if (j == len2) {
                                j = 0;
                                totalCount++;
                            }
                        }
                    }
                }
                
                return totalCount / n2;
            }
            repeatCount[j] = count;
            nextIndex[j] = k + 1;
        }
        
        return count / n2;
    }
};
Let's break down how this solution works:

Key Insight:
We need to find how many times [s2, n2] can be formed from [s1, n1] by removing characters
The final answer is how many complete [s2, n2] sequences we can make
Algorithm Approach:
Process s1 one repetition at a time
For each character in s1, try to match it with current position in s2
Keep track of how many complete s2 we form
Look for repeating patterns to optimize for large n1
Pattern Detection:
Use repeatCount and nextIndex arrays to detect cycles
When we find a cycle, we can calculate how many times it repeats
Then process only the remaining iterations after complete cycles
Time Complexity:
In worst case: O(n1 * len1)
When cycles are detected: O(len1 * len2 + n1)
Space Complexity: O(len2)
Example Walkthrough (s1="acb", n1=4, s2="ab", n2=2):
First s1: "acb" -> matches "ab" (count=1)
Second s1: "acb" -> matches another "ab" (count=2)
We can form 2 complete "ab" sequences
Since n2=2, answer is 2/2 = 1
But problem asks for maximum m, so we get 2