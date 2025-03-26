#include <iostream>
using namespace std;

class Solution {
public:
    int sumOfSquares(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = sumOfSquares(n);
        while (fast != 1 && slow != fast) {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast)); // Move twice as fast
        }
        return fast == 1;
    }
};

int main() {
    Solution solution;
    cout << boolalpha << solution.isHappy(19) << endl;  // Output: true
    cout << boolalpha << solution.isHappy(2) << endl;   // Output: false
    return 0;
}
