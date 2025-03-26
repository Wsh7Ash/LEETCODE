#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0; // No primes less than 2
        
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return count(isPrime.begin(), isPrime.end(), true);
    }
};

// Example usage
int main() {
    Solution solution;
    int n = 10;
    cout << "Number of primes less than " << n << ": " << solution.countPrimes(n) << endl;
    return 0;
}
