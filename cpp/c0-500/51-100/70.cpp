#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
    if (n == 1) return 1;  // Base case: only 1 way to climb 1 step
    if (n == 2) return 2;  // Base case: 2 ways to climb 2 steps

    int first = 1, second = 2, result = 0;

    // Start from the 3rd step up to nth step
    for (int i = 3; i <= n; i++) {
        result = first + second;  // The number of ways to reach the current step
        first = second;  // Move the second to first
        second = result;  // Move the result to second
    }

    return result;  // Return the number of ways to reach the nth step
}

int main() {
    cout << climbStairs(2) << endl;  // Output: 2
    cout << climbStairs(3) << endl;  // Output: 3
    cout << climbStairs(4) << endl;  // Output: 5
    cout << climbStairs(5) << endl;  // Output: 8

    return 0;
}
