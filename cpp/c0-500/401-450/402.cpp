class Solution {
    public:
        string removeKdigits(string num, int k) {
            string stack;  // Using string as a stack
            
            // Process each digit
            for (char digit : num) {
                // Remove larger digits from stack while we can
                while (!stack.empty() && k > 0 && stack.back() > digit) {
                    stack.pop_back();
                    k--;
                }
                stack.push_back(digit);
            }
            
            // If k > 0, remove remaining digits from end
            while (k > 0 && !stack.empty()) {
                stack.pop_back();
                k--;
            }
            
            // Remove leading zeros
            int start = 0;
            while (start < stack.length() && stack[start] == '0') {
                start++;
            }
            
            // Handle empty result
            if (start == stack.length()) {
                return "0";
            }
            
            return stack.substr(start);
        }
    };
    How this solution works:
    
    Approach:
    Use a monotonic stack to build smallest possible number
    Remove larger digits when possible
    Greedy approach: always try to make leftmost digits smaller
    Key Logic:
    For each digit:
    While stack has larger digit and k > 0, remove it
    Add current digit
    Remove remaining k digits from end if needed
    Remove leading zeros
    Example Walkthrough (num = "1432219", k = 3):
    text
    
    Collapse
    
    Wrap
    
    Copy
    Stack progression:
    1 → 1,4 → 1,3 → 1,2 → 1,2,2 → 1,2,1 → 1,2,1,9
    Result: "1219"
    Algorithm Steps:
    Build stack by comparing with previous digits
    Use k removals to eliminate larger digits
    Handle remaining removals
    Clean up leading zeros
    Return "0" if result empty
    Complexity:
    Time: O(n) where n is length of num
    Space: O(n) for the stack string
    Key Features:
    Maintains smallest possible number
    Removes exactly k digits
    Handles leading zeros
    Returns "0" for empty result
    The solution satisfies all constraints:
    
    Works for k from 1 to num.length
    Handles num.length up to 10^5
    Works with digit-only strings
    Handles no leading zeros except zero itself
    For the example cases:
    
    "1432219", k=3 → "1219"
    "10200", k=1 → "200"
    "10", k=2 → "0"
    Alternative Approach (using deque):
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        string removeKdigits(string num, int k) {
            deque<char> dq;
            
            for (char digit : num) {
                while (!dq.empty() && k > 0 && dq.back() > digit) {
                    dq.pop_back();
                    k--;
                }
                dq.push_back(digit);
            }
            
            // Remove remaining k digits
            while (k > 0 && !dq.empty()) {
                dq.pop_back();
                k--;
            }
            
            // Build result skipping leading zeros
            string result;
            bool leadingZero = true;
            for (char c : dq) {
                if (leadingZero && c == '0') continue;
                leadingZero = false;
                result += c;
            }
            
            return result.empty() ? "0" : result;
        }
    };
    The stack-based approach is optimal because:
    
    Greedily ensures smallest possible number
    Single pass through the string
    Naturally handles all edge cases
    Maintains digit order while removing k digits
    The solution efficiently produces the smallest possible number by always preferring to remove larger digits from the left when possible, which aligns with how number magnitude works.