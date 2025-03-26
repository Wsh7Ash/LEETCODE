class Solution {
    public:
        int integerReplacement(int n) {
            // Use long to handle potential overflow when n+1
            unordered_map<long, int> memo;
            return replace(static_cast<long>(n), memo);
        }
        
    private:
        int replace(long n, unordered_map<long, int>& memo) {
            // Base cases
            if (n == 1) return 0;
            if (memo.count(n)) return memo[n];
            
            int steps;
            if (n % 2 == 0) {
                // Even number: only one choice
                steps = 1 + replace(n / 2, memo);
            } else {
                // Odd number: try both n+1 and n-1
                steps = 1 + min(replace(n + 1, memo), replace(n - 1, memo));
            }
            
            memo[n] = steps;
            return steps;
        }
    };
    How this solution works:
    
    Approach:
    Uses dynamic programming with memoization
    For even numbers: divide by 2
    For odd numbers: try both +1 and -1, take minimum
    Memoizes results to avoid recalculating
    Key Insights:
    Use long to prevent integer overflow (when n+1 for max int)
    Even numbers have one optimal path
    Odd numbers need to check both options
    Memoization prevents exponential time complexity
    Example Walkthrough (n = 7):
    text
    
    Collapse
    
    Wrap
    
    Copy
    7 (odd) → min(8, 6)
    - 8 (even) → 4 → 2 → 1 (3 steps)
    - 6 (even) → 3 → 2 → 1 (3 steps)
    Total: 1 + 3 = 4 steps
    Alternative Optimized Solution (Greedy with Bit Manipulation):
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        int integerReplacement(int n) {
            long num = n;  // Use long to handle overflow
            int steps = 0;
            
            while (num > 1) {
                if (num % 2 == 0) {
                    num /= 2;
                } else {
                    // For odd numbers, prefer making it divisible by 4
                    if (num == 3 || (num + 1) % 4 == 0) {
                        num--;
                    } else {
                        num++;
                    }
                }
                steps++;
            }
            
            return steps;
        }
    };
    Optimized Solution Explanation:
    
    Logic:
    For even: divide by 2
    For odd:
    If 3, subtract 1 (3→2→1 is optimal)
    Otherwise, choose +1 or -1 based on which gets closer to number divisible by 4
    This minimizes steps by aiming for more divisions by 2
    Why it works:
    More divisions by 2 means fewer total steps
    For odd numbers, getting to a number divisible by 4 allows two divisions
    Special case for 3 because 3→2 is better than 3→4
    Complexity:
    Time: O(log n) - each step reduces number size
    Space: O(1) - no extra space beyond variables
    Example (n = 7):
    text
    
    Collapse
    
    Wrap
    
    Copy
    7 → 8 (because 8%4=0)
    8 → 4
    4 → 2
    2 → 1
    Steps = 4
    Both solutions handle:
    
    n from 1 to 2³¹-1
    All example cases
    Return minimum operations
    The greedy solution is more efficient in practice:
    
    Avoids recursion overhead
    Constant space vs O(log n) for memoization
    Still guarantees optimal result
    The key optimization in the greedy approach is recognizing that for odd numbers (except 3), moving toward a number divisible by 4 will lead to faster convergence to 1 through more efficient divisions by 2.