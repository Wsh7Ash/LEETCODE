#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            columnNumber--; // Convert to 0-based index
            char letter = 'A' + (columnNumber % 26);
            result = letter + result; // Prepend the character
            columnNumber /= 26;
        }
        
        return result;
    }
};

// **Example Usage**
int main() {
    Solution sol;
    cout << sol.convertToTitle(1) << endl;    // Output: "A"
    cout << sol.convertToTitle(28) << endl;   // Output: "AB"
    cout << sol.convertToTitle(701) << endl;  // Output: "ZY"
    cout << sol.convertToTitle(2147483647) << endl; // Output: "FXSHRXW"
    return 0;
}
