#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t reversed = 0;
    for (int i = 0; i < 32; i++) {
        reversed = (reversed << 1) | (n & 1); // Shift left and add LSB
        n >>= 1; // Shift input right
    }
    return reversed;
}

// Example usage
int main() {
    uint32_t num1 = 0b00000010100101000001111010011100;
    cout << reverseBits(num1) << endl; // Output: 964176192

    uint32_t num2 = 0b11111111111111111111111111111101;
    cout << reverseBits(num2) << endl; // Output: 3221225471

    return 0;
}
