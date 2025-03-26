#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_set<string> wordSet;
    unordered_map<int, vector<string>> memo;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Initialize the wordSet for fast lookup
        for (const string& word : wordDict) {
            wordSet.insert(word);
        }
        
        // Start the backtracking with memoization
        return backtrack(s, 0);
    }
    
    vector<string> backtrack(const string& s, int start) {
        // If we've already computed the result for this substring, return it
        if (memo.find(start) != memo.end()) {
            return memo[start];
        }
        
        vector<string> result;
        int n = s.length();
        
        // If we've reached the end of the string, we return an empty string to mark the end of a valid sentence
        if (start == n) {
            result.push_back("");
            return result;
        }
        
        // Try all possible substrings starting at `start` index
        for (int i = start + 1; i <= n; ++i) {
            string word = s.substr(start, i - start);
            // If the word exists in the dictionary, process it
            if (wordSet.find(word) != wordSet.end()) {
                // Get all the sentences from the rest of the string
                vector<string> rest = backtrack(s, i);
                // Add the current word to each sentence from the rest
                for (string& sentence : rest) {
                    if (sentence.empty()) {
                        result.push_back(word);  // If rest is empty, just add the current word
                    } else {
                        result.push_back(word + " " + sentence);
                    }
                }
            }
        }
        
        // Memoize the result for the current start index
        memo[start] = result;
        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "catsanddog";
    vector<string> wordDict1 = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result1 = sol.wordBreak(s1, wordDict1);
    for (const string& sentence : result1) {
        cout << sentence << endl;
    }
    
    // Test Case 2
    string s2 = "pineapplepenapple";
    vector<string> wordDict2 = {"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> result2 = sol.wordBreak(s2, wordDict2);
    for (const string& sentence : result2) {
        cout << sentence << endl;
    }
    
    // Test Case 3
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    vector<string> result3 = sol.wordBreak(s3, wordDict3);
    for (const string& sentence : result3) {
        cout << sentence << endl;
    }

    return 0;
}
