class Solution {
    public:
        int lastRemaining(int n) {
            int first = 1;    // First number in current sequence
            int step = 1;     // Current step size between numbers
            int remaining = n; // Numbers remaining
            bool leftToRight = true; // Direction flag
            
            while (remaining > 1) {
                if (leftToRight || remaining % 2 == 1) {
                    // Update first when going left->right 
                    // or when remaining is odd (right->left affects first)
                    first += step;
                }
                
                // Halve the remaining numbers
                remaining /= 2;
                // Double the step size
                step *= 2;
                // Switch direction
                leftToRight = !leftToRight;
            }
            
            return first;
        }
    };
    Let's break down how this solution works:
    
    Key Insights:
    We don't need to simulate the entire array
    We can track just the first number and step size
    Pattern emerges: step size doubles each iteration
    Number of elements halves each iteration
    Variables:
    first: Tracks the first number in current sequence
    step: Distance between consecutive numbers
    remaining: Count of numbers left
    leftToRight: Direction of current elimination
    Logic:
    When going left->right: always update first number
    When going right->left: update first only if remaining is odd
    After each pass:
    remaining numbers halve
    step size doubles
    direction switches
    Example walkthrough (n = 9):
    text
    
    Collapse
    
    Wrap
    
    Copy
    Initial: [1,2,3,4,5,6,7,8,9], first=1, step=1, remaining=9
    L->R: [2,4,6,8], first=2, step=2, remaining=4
    R->L: [2,6], first=2, step=4, remaining=2
    L->R: [6], first=6, step=8, remaining=1
    Result: 6
    Why it works:
    Left->Right: Always removes first number, so first += step
    Right->Left:
    If odd count: removes last number and affects first
    If even count: removes last number but first stays same
    Step doubles as we eliminate every other number
    Remaining halves each iteration
    Time and Space Complexity:
    
    Time Complexity: O(log n) - we halve the numbers each iteration
    Space Complexity: O(1) - constant extra space
    The solution handles all constraints:
    
    Works for 1 <= n <= 10^9
    Correctly returns single remaining number
    Handles edge case n=1
    This is much more efficient than simulating the actual array elimination, which would be O(n) space and O(n log n) time. The mathematical approach allows us to solve it in logarithmic time by tracking just the pattern of the first number's movement.