class Solution {
    private:
        const int MOD = 1337;
        
        // Fast modular exponentiation
        int powMod(int base, int exp) {
            base %= MOD;
            int result = 1;
            
            while (exp > 0) {
                if (exp & 1) {  // If exponent is odd
                    result = (result * base) % MOD;
                }
                base = (base * base) % MOD;
                exp >>= 1;  // Divide exponent by 2
            }
            return result;
        }
        
    public:
        int superPow(int a, vector<int>& b) {
            if (b.empty()) return 1;
            
            int result = 1;
            a %= MOD;
            
            // Process each digit from right to left
            for (int i = b.size() - 1; i >= 0; i--) {
                // Raise to power of current digit
                result = (result * powMod(a, b[i])) % MOD;
                // Prepare a for next iteration (raise to power 10)
                a = powMod(a, 10);
            }
            
            return result;
        }
    };
    Let's break down how this works:
    
    Key Concepts:
    Uses modular arithmetic property: (a * b) mod m = ((a mod m) * (b mod m)) mod m
    Breaks down large exponent into digits
    Uses fast modular exponentiation for efficiency
    Algorithm:
    powMod(base, exp): Fast modular exponentiation
    Uses square-and-multiply algorithm
    Keeps numbers small using modulo at each step
    superPow(a, b): Main function
    Processes exponent digits from right to left
    For each digit, multiplies result by a^(digit)
    Updates a to a^10 for next position
    Example Walkthrough:
    text
    Wrap
    Copy
    a = 2, b = [1,0] (represents 10)
    - Initial: result = 1, a = 2
    - i=1: b[1]=0
      - result = 1 * 2^0 = 1
      - a = 2^10 = 1024 % 1337 = 1024
    - i=0: b[0]=1
      - result = 1 * 1024^1 = 1024
    Return 1024
    
    a = 2, b = [3]
    - result = 1 * 2^3 = 8
    Return 8
    Mathematical Basis:
    For a^b where b = [d₀,d₁,...,dₙ]:
    a^b = a^(d₀10ⁿ + d₁10ⁿ⁻¹ + ... + dₙ)
    Can be computed as: (...((a^d₀)^10 * a^d₁)^10 * ... * a^dₙ)
    Time Complexity:
    powMod: O(log exp)
    superPow: O(n * log 10) where n is length of b
    Total: O(n)
    Space Complexity: O(1)
    Why It Works:
    Keeps all intermediate results under MOD
    Handles large exponents through digit-by-digit processing
    Uses efficient exponentiation algorithm
    The solution meets all constraints:
    
    Works for 1 ≤ a ≤ 2³¹-1
    Handles b arrays of length 1 to 2000
    Works with digits 0-9
    Assumes no leading zeros in b
    This solution efficiently computes large powers modulo 1337 by:
    
    Breaking down the exponent into manageable digits
    Using fast modular exponentiation
    Maintaining all intermediate results within the modulus
    Avoiding integer overflow through continuous modular reduction