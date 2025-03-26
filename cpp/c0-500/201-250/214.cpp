class Solution {
    public:
        string shortestPalindrome(string s) {
            int n = s.length();
            if (n == 0) return "";
            
            // Create a modified string: s + "#" + reverse(s)
            string rev_s = s;
            reverse(rev_s.begin(), rev_s.end());
            string combined = s + "#" + rev_s;
            
            // Build KMP partial match table (LPS array)
            vector<int> lps(combined.length(), 0);
            int len = 0;  // Length of previous longest prefix suffix
            
            // Start from second character
            for (int i = 1; i < combined.length(); i++) {
                // Update len based on mismatches
                while (len > 0 && combined[i] != combined[len]) {
                    len = lps[len - 1];
                }
                
                // If characters match
                if (combined[i] == combined[len]) {
                    len++;
                }
                lps[i] = len;
            }
            
            // The last value in lps tells us the length of longest palindromic prefix
            int palin_len = lps[combined.length() - 1];
            
            // Take the remaining suffix, reverse it, and add to front
            string suffix = s.substr(palin_len);
            reverse(suffix.begin(), suffix.end());
            
            return suffix + s;
        }
    };