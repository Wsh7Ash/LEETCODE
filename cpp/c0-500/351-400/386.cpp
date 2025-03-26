class Solution {
    public:
        vector<int> lexicalOrder(int n) {
            vector<int> result;
            int curr = 1;
            
            // Generate n numbers
            for (int i = 0; i < n; i++) {
                result.push_back(curr);
                
                // Try to multiply by 10 first (go deeper)
                if (curr * 10 <= n) {
                    curr *= 10;
                }
                // If can't go deeper, increment and handle carry
                else {
                    // Skip trailing zeros
                    while (curr % 10 == 9 || curr >= n) {
                        curr /= 10;
                    }
                    curr++;
                }
            }
            
            return result;
        }
    };
    Let's break down how this solution works:
    
    Approach:
    Think of numbers as a tree where each node can have children 0-9
    Use DFS-like traversal but with specific rules
    Generate numbers sequentially in lexical order
    Algorithm:
    Start with 1
    At each step:
    Add current number to result
    Try to multiply by 10 (go deeper) if within n
    If can't go deeper, increment and handle overflow
    Continue until we have n numbers
    Key Logic:
    Multiplying by 10 gives next level (1 -> 10 -> 100)
    When hitting limit or 9, go back up and increment
    Skip trailing zeros by dividing by 10
    Example Walkthrough (n = 13):
    text
    
    Collapse
    
    Wrap
    
    Copy
    curr    result
    1       [1]
    10      [1,10]
    11      [1,10,11]
    12      [1,10,11,12]
    13      [1,10,11,12,13]
    2       [1,10,11,12,13,2]  (13->1->2)
    3       [1,10,11,12,13,2,3]
    4       [1,10,11,12,13,2,3,4]
    ...and so on
    Time and Space Complexity:
    Time Complexity: O(n)
    Generates exactly n numbers
    Each operation is O(1)
    Space Complexity: O(1) extra space
    Output array doesn't count as extra space
    Only uses curr variable
    Why it's Lexicographical:
    Goes deep first (1,10,11,12,13 before 2)
    Handles single digits before moving to next
    Naturally follows string ordering
    The solution meets all constraints:
    
    Works for n from 1 to 5*10^4
    Runs in O(n) time
    Uses O(1) extra space (besides output)
    Produces correct lexicographical ordering
    This is an elegant solution that avoids:
    
    Generating all numbers and sorting (O(n log n))
    Using recursive DFS with stack (O(log n) space)
    Converting to strings (extra space)
    Instead, it cleverly manipulates numbers directly to achieve the desired order while maintaining the required time and space complexity.