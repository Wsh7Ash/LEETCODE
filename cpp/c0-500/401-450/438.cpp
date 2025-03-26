Problem Explanation:
We are given two strings, s and p. We need to find all the starting indices in s where a substring of length equal to p is an anagram of p. An anagram is a rearrangement of letters, so the frequency of each character in the substring must match the frequency of characters in p.

Example:
Input: s = "cbaebabacd", p = "abc"

Output: [0, 6]

Explanation:

The substring starting at index 0 is "cba", which is an anagram of "abc".

The substring starting at index 6 is "bac", which is also an anagram of "abc".

Approach:
Sliding Window: We will use a sliding window of size equal to the length of p to traverse through s.

Character Frequency Count: We will maintain two frequency arrays (or hash maps) to count the frequency of characters in p and the current window in s.

Comparison: For each window in s, we will compare its character frequency with that of p. If they match, it means the current window is an anagram of p, and we will record the starting index.

Efficient Updates: As the window slides, we will efficiently update the frequency count by removing the leftmost character of the previous window and adding the new character on the right.

C++ Code with English and Arabic Comments:
cpp
Copy
#include <vector>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result; // To store the starting indices of anagrams
        // لتخزين المؤشرات البدائية للأناغرامات
        
        if (s.size() < p.size()) {
            return result; // If s is shorter than p, no anagrams are possible
            // إذا كانت s أقصر من p، فلا توجد أناغرامات ممكنة
        }
        
        // Arrays to store the frequency of characters in p and the current window in s
        // مصفوفات لتخزين تكرار الأحرف في p والنافذة الحالية في s
        array<int, 26> pCount = {0};
        array<int, 26> sCount = {0};
        
        // Initialize the frequency count for p
        // تهيئة تعداد التكرارات لـ p
        for (char c : p) {
            pCount[c - 'a']++;
        }
        
        // Initialize the frequency count for the first window in s
        // تهيئة تعداد التكرارات للنافذة الأولى في s
        for (int i = 0; i < p.size(); i++) {
            sCount[s[i] - 'a']++;
        }
        
        // Compare the first window
        // مقارنة النافذة الأولى
        if (sCount == pCount) {
            result.push_back(0);
        }
        
        // Slide the window through s
        // تحريك النافذة عبر s
        for (int i = p.size(); i < s.size(); i++) {
            // Remove the leftmost character of the previous window
            // إزالة الحرف الأقصى لليسار من النافذة السابقة
            sCount[s[i - p.size()] - 'a']--;
            
            // Add the new character to the window
            // إضافة الحرف الجديد إلى النافذة
            sCount[s[i] - 'a']++;
            
            // Compare the current window with p
            // مقارنة النافذة الحالية مع p
            if (sCount == pCount) {
                result.push_back(i - p.size() + 1);
            }
        }
        
        return result;
    }
};
Explanation:
Sliding Window: We use a window of size p.size() to traverse s. This ensures that we only consider substrings of the required length.

Frequency Count: We maintain two arrays (pCount and sCount) to count the frequency of characters in p and the current window in s.

Efficient Updates: As the window slides, we update the frequency count by decrementing the count of the character that is left behind and incrementing the count of the new character that enters the window.

Comparison: If the frequency counts of the current window and p match, we record the starting index of the window.

Complexity:
Time Complexity: O(N), where N is the length of s. We traverse s once, and each comparison of frequency counts takes constant time.

Space Complexity: O(1), since the frequency arrays are of fixed size (26 for lowercase English letters).

This approach efficiently finds all starting indices of anagrams of p in s using the sliding window technique and character frequency counting.