#include <vector>
#include <climits>

class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) {
        int k = primes.size();
        std::vector<long> dp(n + 1);  // Using long to avoid overflow during multiplication
        std::vector<int> pointers(k, 1);  // Pointers to track position in dp array
        std::vector<long> nextValues(k);  // Next possible values for each prime
        
        dp[1] = 1;  // First super ugly number is 1
        for (int i = 0; i < k; i++) {
            nextValues[i] = primes[i];
        }
        
        for (int i = 2; i <= n; i++) {
            // Find minimum value among next possible numbers
            long minVal = LLONG_MAX;
            for (int j = 0; j < k; j++) {
                minVal = std::min(minVal, nextValues[j]);
            }
            dp[i] = minVal;
            
            // Update pointers and next values for primes that produced minVal
            for (int j = 0; j < k; j++) {
                if (nextValues[j] == minVal) {
                    pointers[j]++;
                    nextValues[j] = dp[pointers[j]] * primes[j];
                }
            }
        }
        
        return static_cast<int>(dp[n]);
    }
};
Let's break down how this works:

Approach:
Maintain a dp array where dp[i] is the ith super ugly number
Use pointers to track which number each prime should multiply next
At each step, take the minimum of all possible next numbers
Key Components:
dp: stores super ugly numbers
pointers: index of next dp element to multiply with each prime
nextValues: next possible super ugly number for each prime
Algorithm:
Start with 1 as first number
For each position:
Find minimum among all next possible values
Update that position with minimum
Advance pointers for primes that produced the minimum
Here's a test program:

cpp
Wrap
Copy
#include <iostream>
#include <vector>

class Solution {
    // ... (same implementation as above)
};

int main() {
    Solution solution;
    
    // Test case 1
    std::vector<int> primes1 = {2, 7, 13, 19};
    int n1 = 12;
    std::cout << "Test 1: " << solution.nthSuperUglyNumber(n1, primes1) << std::endl;
    
    // Test case 2
    std::vector<int> primes2 = {2, 3, 5};
    int n2 = 1;
    std::cout << "Test 2: " << solution.nthSuperUglyNumber(n2, primes2) << std::endl;
    
    // Additional test cases
    std::vector<int> primes3 = {2, 3};
    int n3 = 5;
    std::cout << "Test 3: " << solution.nthSuperUglyNumber(n3, primes3) << std::endl;
    
    return 0;
}
Expected Output:

text
Wrap
Copy
Test 1: 32
Test 2: 1
Test 3: 6
Complexity:

Time: O(n * k) where n is the target number and k is number of primes
Space: O(n + k) for dp array and pointers/nextValues
Key Features:

Uses long to handle intermediate multiplications safely
Works within constraints:
1 ≤ n ≤ 10^5
1 ≤ primes.length ≤ 100
2 ≤ primes[i] ≤ 1000
Returns result guaranteed to fit in 32-bit integer
Handles unique, sorted primes correctly
Example 1 Walkthrough:

n = 12, primes = [2,7,13,19]
Sequence: [1,2,4,7,8,13,14,16,19,26,28,32]
Each number is product of previous numbers with given primes
The solution efficiently generates super ugly numbers in order, handling all edge cases and constraints properly while avoiding integer overflow issues during intermediate calculations.