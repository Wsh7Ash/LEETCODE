#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) { // Find common prefix
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift; // Restore shifted bits
    }
};

int main() {
    Solution solution;
    cout << solution.rangeBitwiseAnd(5, 7) << endl;  // Output: 4
    cout << solution.rangeBitwiseAnd(0, 0) << endl;  // Output: 0
    cout << solution.rangeBitwiseAnd(1, 2147483647) << endl;  // Output: 0
    return 0;
}
