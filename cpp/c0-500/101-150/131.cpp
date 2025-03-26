#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentPartition;
        backtrack(s, 0, currentPartition, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& currentPartition, vector<vector<string>>& result) {
        // If we've reached the end of the string, add the current partition to the result
        if (start >= s.length()) {
            result.push_back(currentPartition);
            return;
        }

        // Try all possible substrings starting at 'start'
        for (int end = start; end < s.length(); ++end) {
            // If the substring is a palindrome, add it to the current partition
            if (isPalindrome(s, start, end)) {
                currentPartition.push_back(s.substr(start, end - start + 1));
                // Recur to partition the remaining substring
                backtrack(s, end + 1, currentPartition, result);
                // Backtrack: remove the last added substring and try a different partition
                currentPartition.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};