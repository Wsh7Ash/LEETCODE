#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        
        // Iterate over the string columnTitle
        for (char c : columnTitle) {
            result = result * 26 + (c - 'A' + 1);
        }
        
        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    cout << sol.titleToNumber("A") << endl;  // Output: 1
    cout << sol.titleToNumber("AB") << endl; // Output: 28
    cout << sol.titleToNumber("ZY") << endl; // Output: 701
    
    return 0;
}
