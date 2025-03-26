#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int zeroes = 0;
        
        // Count factors of 5 in the factorial
        while (n >= 5) {
            n /= 5;
            zeroes += n;
        }
        
        return zeroes;
    }
};

// Example usage
int main() {
    Solution sol;
    cout << sol.trailingZeroes(3) << endl;  // Output: 0
    cout << sol.trailingZeroes(5) << endl;  // Output: 1
    cout << sol.trailingZeroes(25) << endl; // Output: 6
    
    return 0;
}
