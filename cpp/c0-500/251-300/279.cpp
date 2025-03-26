class Solution {
    public:
        int numSquares(int n) {
            // dp[i] represents the least number of perfect squares that sum to i
            vector<int> dp(n + 1, INT_MAX);
            
            // Base case
            dp[0] = 0;
            
            // Fill dp array
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j * j <= i; j++) {
                    // For each i, try all perfect squares less than or equal to i
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }
            
            return dp[n];
        }
    };
    How it works:
    
    Dynamic Programming Approach:
    dp[i] = minimum number of perfect squares that sum to i
    For each number i, try all possible perfect squares j² ≤ i
    dp[i] = min(dp[i], dp[i - j²] + 1)
    Implementation:
    Initialize dp array with INT_MAX
    dp[0] = 0 as base case (0 requires 0 squares)
    For each i from 1 to n:
    Try each perfect square j²
    Update dp[i] with minimum of current value and dp[i - j²] + 1
    Alternative Mathematical Solution (based on Lagrange's Four Square Theorem):
    
    cpp
    Wrap
    Copy
    class Solution {
    public:
        // Check if n is a perfect square
        bool isSquare(int n) {
            int sqrt_n = sqrt(n);
            return sqrt_n * sqrt_n == n;
        }
        
        int numSquares(int n) {
            // If n is a perfect square
            if (isSquare(n)) return 1;
            
            // Check for sum of two squares
            for (int i = 1; i * i <= n; i++) {
                if (isSquare(n - i * i)) return 2;
            }
            
            // Legendre's three-square theorem
            while (n % 4 == 0) n /= 4;
            if (n % 8 == 7) return 4;
            
            // If not 4, must be 3
            return 3;
        }
    };
    Time Complexity:
    
    DP solution: O(n * √n)
    Outer loop: O(n)
    Inner loop: O(√n) for checking squares up to i
    Math solution: O(√n) - much faster but less intuitive
    Space Complexity:
    
    DP solution: O(n) for the dp array
    Math solution: O(1)
    Examples:
    
    n = 12 (DP):
    dp[1] = 1 (1)
    dp[4] = 1 (4)
    dp[12] = min(dp[12], dp[8] + 1, dp[3] + 1) = 3
    Result: 3 (4 + 4 + 4)
    n = 13 (DP):
    dp[4] = 1
    dp[9] = 1
    dp[13] = min(dp[13], dp[9] + 1) = 2
    Result: 2 (4 + 9)
    The DP solution is more general and guaranteed to find the minimum number, while the mathematical solution leverages number theory (Lagrange's Four Square Theorem and Legendre's Three Square Theorem) for better performance. Both handle all constraints (1 ≤ n ≤ 10⁴).
    
    The DP solution is typically preferred in interviews as it's more straightforward to understand and derive, though the mathematical solution showcases deeper number theory knowledge if time permits explanation.