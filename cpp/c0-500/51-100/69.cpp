#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x == 0) return 0;  // Square root of 0 is 0

    int left = 1, right = x, result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // If mid * mid equals x, we have found the exact square root
        if (mid * mid == x) {
            return mid;
        }
        // If mid * mid is less than x, search the right half
        else if (mid * mid < x) {
            left = mid + 1;
            result = mid;  // Update result to the last valid mid
        }
        // If mid * mid is greater than x, search the left half
        else {
            right = mid - 1;
        }
    }

    return result;  // Return the integer square root
}

int main() {
    cout << mySqrt(4) << endl;  // Output: 2
    cout << mySqrt(8) << endl;  // Output: 2
    cout << mySqrt(16) << endl; // Output: 4
    cout << mySqrt(25) << endl; // Output: 5
    cout << mySqrt(0) << endl;  // Output: 0

    return 0;
}
