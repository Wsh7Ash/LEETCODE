class Solution {
    public:
        bool isUgly(int n) {
            // Handle non-positive numbers
            if (n <= 0) {
                return false;
            }
            
            // 1 is considered an ugly number
            if (n == 1) {
                return true;
            }
            
            // Array of allowed prime factors
            int primes[] = {2, 3, 5};
            
            // Keep dividing by 2, 3, 5 as long as possible
            for (int prime : primes) {
                while (n % prime == 0) {
                    n /= prime;
                }
            }
            
            // If n becomes 1, all factors were 2, 3, or 5
            // If n > 1, there are other prime factors
            return n == 1;
        }
    };
    How it works:
    
    Base Cases:
    If n ≤ 0, return false (negative numbers and zero aren't ugly numbers)
    If n = 1, return true (1 is considered ugly by definition as it has no prime factors)
    Main Logic:
    We use an array of the allowed prime factors: [2, 3, 5]
    For each prime factor:
    While n is divisible by that prime, keep dividing n by it
    After dividing by all possible 2s, 3s, and 5s:
    If n becomes 1, it means all prime factors were 2, 3, or 5 (return true)
    If n > 1, it means there’s at least one other prime factor (return false)
    Time Complexity: O(log n) - The while loops run proportional to the number of times n can be divided by 2, 3, and 5.
    Space Complexity: O(1) - We only use a fixed-size array and a few variables.
    
    Example runs:
    
    n = 6:
    Divide by 2: 6 → 3
    Divide by 3: 3 → 1
    n = 1, return true
    n = 1:
    Immediate return true
    n = 14:
    Divide by 2: 14 → 7
    Can't divide by 3 or 5
    n = 7 > 1, return false