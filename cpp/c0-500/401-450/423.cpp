#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string originalDigits(string s) {
        // Array to store count of each digit (0-9)
        vector<int> count(10, 0);
        
        // Count frequency of each character
        vector<int> charCount(26, 0);
        for (char c : s) {
            charCount[c - 'a']++;
        }
        
        // Process digits based on unique letters
        // "zero" - only number with 'z'
        count[0] = charCount['z' - 'a'];
        // "two" - only number with 'w'
        count[2] = charCount['w' - 'a'];
        // "four" - only number with 'u'
        count[4] = charCount['u' - 'a'];
        // "six" - only number with 'x'
        count[6] = charCount['x' - 'a'];
        // "eight" - only number with 'g'
        count[8] = charCount['g' - 'a'];
        
        // "three" - only remaining number with 'h' after eight
        count[3] = charCount['h' - 'a'] - count[8];
        // "five" - only remaining number with 'f' after four
        count[5] = charCount['f' - 'a'] - count[4];
        // "seven" - only remaining number with 's' after six
        count[7] = charCount['s' - 'a'] - count[6];
        
        // "one" - only remaining number with 'o' after zero, two, four
        count[1] = charCount['o' - 'a'] - count[0] - count[2] - count[4];
        // "nine" - only remaining number with 'i' after five, six, eight
        count[9] = charCount['i' - 'a'] - count[5] - count[6] - count[8];
        
        // Construct the result string
        string result;
        for (int i = 0; i < 10; i++) {
            result.append(count[i], '0' + i);
        }
        
        return result;
    }
};
Let's break down how this solution works:

Key Strategy:
Some numbers have unique letters that appear only in their spelling:
0 (zero) - 'z'
2 (two) - 'w'
4 (four) - 'u'
6 (six) - 'x'
8 (eight) - 'g'
After identifying these, we can deduce the remaining numbers using other distinctive letters and subtraction.
Algorithm Steps:
First, count frequency of all characters in the input string
Identify numbers with unique letters first (0,2,4,6,8)
Then deduce remaining numbers (3,5,7,1,9) by subtracting already counted instances
Build result string in ascending order
Letter Dependencies:
'h' appears in eight(8) and three(3)
'f' appears in four(4) and five(5)
's' appears in six(6) and seven(7)
'o' appears in zero(0), two(2), four(4), and one(1)
'i' appears in five(5), six(6), eight(8), and nine(9)
Time and Space Complexity:
Time Complexity: O(n) where n is length of input string
Space Complexity: O(1) since we use fixed-size arrays
For Example 1: "owoztneoer"

'z' → count[0] = 1
'w' → count[2] = 1
'o' = 2, minus count[0] and count[2] → count[1] = 1
Result: "012"
For Example 2: "fviefuro"

'u' → count[4] = 1
'f' = 2, minus count[4] → count[5] = 1
Result: "45"