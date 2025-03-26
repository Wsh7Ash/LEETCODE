#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n == 0) return 0;

        // Step 1: Precompute all palindrome substrings
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        // Every single character is a palindrome
        for (int i = 0; i < n; ++i) {
            isPalindrome[i][i] = true;
        }

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; ++i) {
            isPalindrome[i][i + 1] = (s[i] == s[i + 1]);
        }

        // Check for substrings of length > 2
        for (int length = 3; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
            }
        }

        // Step 2: Compute the minimum cuts
        vector<int> minCuts(n);

        for (int i = 0; i < n; ++i) {
            // Initialize with the maximum possible cuts
            minCuts[i] = i;

            // Check if the entire substring s[0...i] is a palindrome
            if (isPalindrome[0][i]) {
                minCuts[i] = 0;
                continue;
            }

            // Try all possible partitions
            for (int j = 0; j < i; ++j) {
                if (isPalindrome[j + 1][i]) {
                    minCuts[i] = min(minCuts[i], minCuts[j] + 1);
                }
            }
        }

        return minCuts[n - 1];
    }
};