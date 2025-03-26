#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        
        dp[0] = true;  // Empty string can always be segmented
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution sol;
    
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << sol.wordBreak(s1, wordDict1) << endl;  // Output: true
    
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << sol.wordBreak(s2, wordDict2) << endl;  // Output: true
    
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << sol.wordBreak(s3, wordDict3) << endl;  // Output: false
    
    return 0;
}
