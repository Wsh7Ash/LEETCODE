#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    string result = "";

    // Iterate from the least significant to the most significant digit
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        // Add digit from 'a' if available
        if (i >= 0) sum += a[i--] - '0';

        // Add digit from 'b' if available
        if (j >= 0) sum += b[j--] - '0';

        // Update carry for the next iteration
        carry = sum / 2;

        // Append the result as the current digit (0 or 1)
        result = to_string(sum % 2) + result;
    }

    return result;
}

int main() {
    string a1 = "11", b1 = "1";
    string a2 = "1010", b2 = "1011";

    cout << addBinary(a1, b1) << endl; // Output: "100"
    cout << addBinary(a2, b2) << endl; // Output: "10101"

    return 0;
}
