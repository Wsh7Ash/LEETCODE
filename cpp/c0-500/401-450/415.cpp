#include <string>
#include <algorithm>

class Solution {
public:
    string addStrings(string num1, string num2) {
        // Start from the rightmost digits
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        string result = "";
        
        // Process digits from right to left
        while (i >= 0 || j >= 0 || carry) {
            // Get digits (0 if we've run out of digits)
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;
            
            // Calculate sum and new carry
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            int digit = sum % 10;
            
            // Prepend current digit to result
            result = char(digit + '0') + result;
            
            // Move to next digits
            i--;
            j--;
        }
        
        return result;
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    // Test case 1
    cout << solution.addStrings("11", "123") << endl;  // Output: "134"
    
    // Test case 2
    cout << solution.addStrings("456", "77") << endl;  // Output: "533"
    
    // Test case 3
    cout << solution.addStrings("0", "0") << endl;    // Output: "0"
    
    return 0;
}
Let's break down how this solution works:

Approach:
Simulate manual addition by processing digits from right to left
Handle carry like in traditional addition
Build result string by prepending each digit
Algorithm:
Start from the end of both strings
While there are digits to process or a carry:
Get current digits (or 0 if we've run out)
Add digits plus carry
Calculate new carry (sum / 10)
Get current digit (sum % 10)
Prepend digit to result
Move to next position
Key Features:
Doesn't convert to integers, works directly with characters
Handles different length inputs
Processes carry correctly
Time Complexity: O(max(N,M)) where N and M are lengths of input strings
Space Complexity: O(max(N,M)) for the result string
Example Walkthrough for "11" + "123":
text

Collapse

Wrap

Copy
i=1, j=2: '1'+'3'+0 = 4,  carry=0, result="4"
i=0, j=1: '1'+'2'+0 = 3,  carry=0, result="34"
i=-1,j=0: '0'+'1'+0 = 1, carry=0, result="134"
Result: "134"
The solution handles all constraints:

Works for strings of length 1 to 10^4
Only processes digit characters (0-9)
Handles cases with no leading zeros (except single "0")
Doesn't use any big integer libraries
Doesn't convert inputs to integers
The code correctly processes all test cases:

"11" + "123" = "134"
"456" + "77" = "533"
"0" + "0" = "0"