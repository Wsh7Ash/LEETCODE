#include <string>
#include <vector>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty() || s.length() < t.length()) {
        return "";
    }

    // Frequency map for characters in t
    vector<int> tCount(128, 0); // ASCII size
    for (char c : t) {
        tCount[c]++;
    }

    // Sliding window pointers
    int left = 0, right = 0;
    int required = t.length(); // Total characters to match
    int minLen = INT_MAX; // Length of the minimum window
    int minStart = 0; // Start index of the minimum window

    // Expand the window
    while (right < s.length()) {
        // If the current character is in t, decrement the required count
        if (tCount[s[right]] > 0) {
            required--;
        }
        tCount[s[right]]--; // Decrement the count in the frequency map
        right++;

        // When all characters are matched, try to shrink the window
        while (required == 0) {
            // Update the minimum window
            if (right - left < minLen) {
                minLen = right - left;
                minStart = left;
            }

            // Move the left pointer to shrink the window
            tCount[s[left]]++;
            if (tCount[s[left]] > 0) {
                required++;
            }
            left++;
        }
    }

    // If no valid window found, return empty string
    return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
}