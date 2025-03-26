#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int numDecodings(std::string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        // dp[i] will store the number of ways to decode the substring s[0:i]
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1; // There's one way to decode an empty string
        dp[1] = s[0] != '0' ? 1 : 0; // Only 1 way to decode a valid single digit

        for (int i = 2; i <= n; i++) {
            // Check for single digit decoding
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            // Check for two digit decoding
            int two_digit = std::stoi(s.substr(i - 2, 2)); // Extract last two digits
            if (two_digit >= 10 && two_digit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    std::string s = "226";
    std::cout << sol.numDecodings(s) << std::endl;  // Output: 3

    s = "12";
    std::cout << sol.numDecodings(s) << std::endl;  // Output: 2

    s = "06";
    std::cout << sol.numDecodings(s) << std::endl;  // Output: 0

    return 0;
}
