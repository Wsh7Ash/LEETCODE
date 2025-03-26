class Solution {
    private:
        void dfs(string& num, int target, long curr_val, long prev_num, 
                 string expr, int pos, vector<string>& result) {
            // Base case: reached end of string
            if (pos == num.length()) {
                if (curr_val == target) {
                    result.push_back(expr);
                }
                return;
            }
            
            // Try all possible numbers starting at pos
            long curr_num = 0;
            string curr_str;
            
            for (int i = pos; i < num.length(); i++) {
                // Build current number
                curr_num = curr_num * 10 + (num[i] - '0');
                curr_str += num[i];
                
                // Avoid numbers with leading zeros
                if (curr_str.length() > 1 && curr_str[0] == '0') break;
                
                // If this is the first number
                if (expr.empty()) {
                    dfs(num, target, curr_num, curr_num, curr_str, i + 1, result);
                } else {
                    // Try addition
                    dfs(num, target, curr_val + curr_num, curr_num, 
                        expr + "+" + curr_str, i + 1, result);
                    
                    // Try subtraction
                    dfs(num, target, curr_val - curr_num, -curr_num, 
                        expr + "-" + curr_str, i + 1, result);
                    
                    // Try multiplication
                    // For multiplication, we need to subtract prev_num and add prev_num * curr_num
                    dfs(num, target, curr_val - prev_num + prev_num * curr_num, 
                        prev_num * curr_num, expr + "*" + curr_str, i + 1, result);
                }
            }
        }
        
    public:
        vector<string> addOperators(string num, int target) {
            vector<string> result;
            if (num.empty()) return result;
            
            dfs(num, target, 0, 0, "", 0, result);
            return result;
        }
    };
    How it works:
    
    Backtracking Approach:
    Use DFS to try all possible ways to split the string and insert operators
    Track current value and previous number for correct multiplication handling
    Key Components:
    curr_val: Running evaluation of the expression
    prev_num: Last number used (needed for multiplication precedence)
    expr: Current expression string being built
    pos: Current position in the input string
    Implementation Details:
    For each position, try all possible numbers starting there
    Handle three operators: +, -, *
    Special handling for multiplication (undo previous addition/subtraction)
    Prevent leading zeros in multi-digit numbers
    Base case checks if final value equals target
    Time Complexity: O(4ⁿ) where n is the length of the string
    
    At each position, we can choose: no operator, +, -, or *
    Exponential due to all possible combinations
    Space Complexity: O(n) for recursion stack depth
    
    Examples:
    
    "123", target=6:
    "1+2+3" → 6
    "123" → 6
    Output: ["123", "1+2+3"]
    "232", target=8:
    "2*3+2" → 8
    "2+3*2" → 8
    Output: ["23+2", "2+32"]
    Key Features:
    
    Handles operator precedence correctly (multiplication before addition/subtraction)
    Avoids leading zeros
    Works within constraints:
    1 ≤ num.length ≤ 10
    -2³¹ ≤ target ≤ 2³¹ - 1
    Uses long to handle potential overflow during calculations
    The solution is complex due to:
    
    Need to maintain correct arithmetic order
    Handling multiplication precedence
    Preventing invalid numbers (leading zeros)
    Building valid expressions recursively