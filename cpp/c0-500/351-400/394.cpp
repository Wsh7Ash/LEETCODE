#include <string>
#include <stack>

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;      // Stack for numbers
        stack<string> stringStack;  // Stack for strings
        string currentString = "";  // Current decoded string
        int currentNum = 0;         // Current number being processed
        
        for (char c : s) {
            if (isdigit(c)) {
                // Build multi-digit number
                currentNum = currentNum * 10 + (c - '0');
            }
            else if (c == '[') {
                // Push current number and string to stacks
                countStack.push(currentNum);
                stringStack.push(currentString);
                // Reset for new nested section
                currentNum = 0;
                currentString = "";
            }
            else if (c == ']') {
                // Pop count and previous string
                int count = countStack.top();
                countStack.pop();
                string prevString = stringStack.top();
                stringStack.pop();
                
                // Build repeated string
                string temp = "";
                for (int i = 0; i < count; i++) {
                    temp += currentString;
                }
                // Append to previous string
                currentString = prevString + temp;
            }
            else {
                // Add character to current string
                currentString += c;
            }
        }
        
        return currentString;
    }
};
How this solution works:

Approach:
Uses two stacks: one for numbers and one for strings
Processes character by character
Builds result incrementally
Key Components:
countStack: Stores repetition counts
stringStack: Stores partial strings
currentString: Current string being built
currentNum: Current number being parsed
Logic Flow:
Digit: Build multi-digit number
'[': Save current state and start new section
']': Process repetition and combine with previous string
Letter: Append to current string
Example Walkthrough (s = "3[a2[c]]"):
text

Collapse

Wrap

Copy
"3" → currentNum = 3
"[" → push 3, push "", reset
"a" → currentString = "a"
"2" → currentNum = 2
"[" → push 2, push "a", reset
"c" → currentString = "c"
"]" → pop 2, pop "a", "c"×2 = "cc", "a"+"cc" = "acc"
"]" → pop 3, pop "", "acc"×3 = "accaccacc"
Result: "accaccacc"
Complexity:
Time: O(n * m) where n is string length and m is max number value
Space: O(n) for the stacks
Key Features:
Handles nested brackets correctly
Supports multi-digit numbers
Builds string incrementally
The solution satisfies all constraints:

Works for s.length from 1 to 30
Handles lowercase letters, digits, and brackets
Processes valid input as per problem statement
Handles numbers from 1 to 300
Alternative Recursive Solution:

cpp

Collapse

Wrap

Copy
class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return decode(s, pos);
    }
    
private:
    string decode(const string& s, int& pos) {
        string result = "";
        int num = 0;
        
        while (pos < s.length()) {
            char c = s[pos];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                pos++;  // Skip '['
                string nested = decode(s, pos);
                while (num > 0) {
                    result += nested;
                    num--;
                }
            }
            else if (c == ']') {
                return result;
            }
            else {
                result += c;
            }
            pos++;
        }
        return result;
    }
};
Both solutions handle all example cases correctly:

"3[a]2[bc]" → "aaabcbc"
"3[a2[c]]" → "accaccacc"
"2[abc]3[cd]ef" → "abcabccdcdcdef"
The stack-based solution might be preferred for better space complexity in practice (avoiding recursive call stack), while the recursive solution might be more intuitive for some readers.