#include <iostream>
#include <cctype>  // for isalnum() and tolower()
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Move left pointer to the next alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move right pointer to the previous alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare the characters after converting to lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            // Move both pointers inward
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution sol;

    // Example 1
    cout << std::boolalpha;  // To print boolean as true/false
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;  // Output: true

    // Example 2
    cout << sol.isPalindrome("race a car") << endl;  // Output: false

    // Example 3
    cout << sol.isPalindrome(" ") << endl;  // Output: true

    return 0;
}
