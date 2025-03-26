#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        // Swap characters from outside moving inward
        while (left < right) {
            // Swap characters
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            
            // Move pointers
            left++;
            right--;
        }
    }
};

// Test code
#include <iostream>
void printVector(const vector<char>& s) {
    for (char c : s) {
        cout << "\"" << c << "\",";
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(s1);
    printVector(s1);  // "o","l","l","e","h"
    
    // Test case 2
    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    solution.reverseString(s2);
    printVector(s2);  // "h","a","n","n","a","H"
    
    return 0;
}
How it works:

Two-Pointer Approach:
Use left pointer starting from beginning
Use right pointer starting from end
Swap characters and move pointers inward
Algorithm:
While left < right:
Swap s[left] and s[right]
Increment left, decrement right
Stop when pointers meet in middle
Example Walkthrough for ["h","e","l","l","o"]:
Initial: "h","e","l","l","o"
left=0, right=4: swap 'h' and 'o' → "o","e","l","l","h"
left=1, right=3: swap 'e' and 'l' → "o","l","l","e","h"
left=2, right=2: stop
Result: "o","l","l","e","h"
Complexity:

Time Complexity: O(n/2) = O(n) - traverse half the array
Space Complexity: O(1) - only uses one temporary variable
Key Features:

In-place modification
Constant extra space
Simple and efficient
Works with odd and even lengths
The solution satisfies all constraints:

Works for length 1 to 10^5
Handles printable ASCII characters
Modifies array in-place
For the examples:

["h","e","l","l","o"] → ["o","l","l","e","h"]
["H","a","n","n","a","H"] → ["h","a","n","n","a","H"]
Alternative Implementation (using swap):

cpp
Wrap
Copy
void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        swap(s[left++], s[right--]);
    }
}
This solution is efficient because:

Uses minimal extra space (O(1))
Makes exactly n/2 swaps
Works directly on input array
Has simple, predictable behavior
Handles all edge cases naturally
The two-pointer approach is optimal for this problem because:

Naturally reverses the array
Requires no additional data structure
Maintains the in-place requirement
Works efficiently for any array size