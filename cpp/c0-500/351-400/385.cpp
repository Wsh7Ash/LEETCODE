/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger>& getList() const;
 * };
 */
class Solution {
    public:
        NestedInteger deserialize(string s) {
            if (s[0] != '[') {
                // Simple integer case
                return NestedInteger(stoi(s));
            }
            
            stack<NestedInteger> stk;
            int num = 0;
            int sign = 1;
            bool hasNum = false;
            
            for (int i = 0; i < s.length(); i++) {
                char c = s[i];
                
                if (c == '[') {
                    // Start a new nested list
                    stk.push(NestedInteger());
                }
                else if (c == '-') {
                    sign = -1;
                }
                else if (isdigit(c)) {
                    num = num * 10 + (c - '0');
                    hasNum = true;
                }
                else if (c == ',' || c == ']') {
                    // Process any accumulated number
                    if (hasNum) {
                        stk.top().add(NestedInteger(sign * num));
                        num = 0;
                        sign = 1;
                        hasNum = false;
                    }
                    
                    if (c == ']' && !stk.empty()) {
                        if (stk.size() > 1) {
                            NestedInteger nested = stk.top();
                            stk.pop();
                            stk.top().add(nested);
                        }
                    }
                }
            }
            
            return stk.top();
        }
    };
    Let's break down how this solution works:
    
    Base Case:
    If string doesn't start with '[', it's a simple integer
    Convert to int using stoi() and return as NestedInteger
    Main Algorithm:
    Uses a stack to handle nested structure
    Processes string character by character
    Tracks current number being built and its sign
    Character Handling:
    '[': Start new nested list by pushing empty NestedInteger
    '-': Set negative sign
    Digit: Build number
    ',' or ']': Process accumulated number and handle nesting
    Key Logic:
    When hitting ',' or ']':
    Add accumulated number (if any) to current list
    If ']' and multiple levels, pop and add to parent list
    Reset number tracking variables after processing
    Time and Space Complexity:
    Time Complexity: O(n) where n is string length
    Space Complexity: O(m) where m is maximum nesting depth
    Example Walkthrough:
    text
    
    Collapse
    
    Wrap
    
    Copy
    Input: "[123,[456,[789]]]"
    Process:
    '[' -> push empty list
    '123' -> build number
    ',' -> add 123 to top list
    '[' -> push new list
    '456' -> build number
    ',' -> add 456 to top list
    '[' -> push new list
    '789' -> build number
    ']' -> add 789 to top list, pop and add to parent
    ']' -> pop and add to parent
    ']' -> return final result
    The solution handles all constraints:
    
    Works for strings of length 1 to 5*10^4
    Processes valid input characters ([], digits, -, ,)
    Handles values in range [-10^6, 10^6]
    Correctly parses valid NestedInteger serializations
    This implementation efficiently handles both simple integers and complex nested structures while maintaining proper nesting relationships in the output NestedInteger object.