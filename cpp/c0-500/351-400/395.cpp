class Solution {
    public:
        int longestSubstring(string s, int k) {
            return longestSubstringUtil(s, 0, s.length(), k);
        }
        
    private:
        int longestSubstringUtil(string& s, int start, int end, int k) {
            // Base case: if substring length is less than k, no solution possible
            if (end - start < k) return 0;
            
            // Count frequency of each character in current substring
            vector<int> count(26, 0);
            for (int i = start; i < end; i++) {
                count[s[i] - 'a']++;
            }
            
            // Check each character in the substring
            for (int i = start; i < end; i++) {
                // If current character appears less than k times
                if (count[s[i] - 'a'] < k) {
                    // Split string at this character and recursively solve
                    int left = longestSubstringUtil(s, start, i, k);
                    int right = longestSubstringUtil(s, i + 1, end, k);
                    return max(left, right);
                }
            }
            
            // If we reach here, entire substring is valid
            return end - start;
        }
    };
    How this solution works:
    
    Approach:
    Uses divide-and-conquer strategy
    If any character appears less than k times, it can't be part of the result
    Split string at such characters and solve recursively
    Key Logic:
    Count frequency of all characters in current substring
    If any character has frequency < k, split there
    Recursively find maximum valid substring length
    If all characters have frequency >= k, return full length
    Example Walkthrough (s = "ababbc", k = 2):
    text
    
    Collapse
    
    Wrap
    
    Copy
    Initial: "ababbc"
    Count: a:2, b:3, c:1
    Split at 'c' (count < 2):
    - "ababb": Count a:2, b:3 -> valid, length 5
    - "": length 0
    Result: 5
    Complexity:
    Time: O(n * h) where n is string length and h is recursion depth
    In worst case, h can be O(n), making it O(n²)
    Space: O(n) for recursion stack + O(1) for count array
    Optimization - Alternative Sliding Window Approach:
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        int longestSubstring(string s, int k) {
            int maxLen = 0;
            
            // Try all possible numbers of unique characters
            for (int uniqueTarget = 1; uniqueTarget <= 26; uniqueTarget++) {
                maxLen = max(maxLen, longestWithUnique(s, k, uniqueTarget));
            }
            
            return maxLen;
        }
        
    private:
        int longestWithUnique(string& s, int k, int uniqueTarget) {
            vector<int> count(26, 0);
            int unique = 0, atLeastK = 0;
            int left = 0, right = 0;
            int maxLen = 0;
            
            while (right < s.length()) {
                // Expand window
                if (count[s[right] - 'a'] == 0) unique++;
                count[s[right] - 'a']++;
                if (count[s[right] - 'a'] == k) atLeastK++;
                right++;
                
                // Shrink window if too many unique characters
                while (unique > uniqueTarget) {
                    if (count[s[left] - 'a'] == k) atLeastK--;
                    count[s[left] - 'a']--;
                    if (count[s[left] - 'a'] == 0) unique--;
                    left++;
                }
                
                // Check if current window is valid
                if (unique == uniqueTarget && unique == atLeastK) {
                    maxLen = max(maxLen, right - left);
                }
            }
            
            return maxLen;
        }
    };
    The sliding window approach:
    
    Tries all possible numbers of unique characters (1 to 26)
    For each target:
    Maintains window with exactly that many unique characters
    Tracks characters meeting k requirement
    Updates max length when all characters meet requirement
    Time Complexity: O(n * 26) = O(n)
    Space Complexity: O(1)
    Both solutions handle:
    
    s.length from 1 to 10^4
    lowercase English letters
    k from 1 to 10^5
    Example cases correctly
    The sliding window approach is more efficient for larger inputs, while the recursive approach might be more intuitive for understanding the problem's structure. For LeetCode's typical input sizes, either would work well, but the sliding window version has better worst-case performance.