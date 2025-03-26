#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // Remove the rightmost 1 bit
        count++;       // Increment count for each removed bit
    }
    return count;
}

// Example usage
int main() {
    uint32_t num1 = 11;          // Binary: 1011, Output: 3
    uint32_t num2 = 128;         // Binary: 10000000, Output: 1
    uint32_t num3 = 2147483645;  // Binary: 1111111111111111111111111111101, Output: 30

    cout << hammingWeight(num1) << endl; // Output: 3
    cout << hammingWeight(num2) << endl; // Output: 1
    cout << hammingWeight(num3) << endl; // Output: 30

    return 0;
}
