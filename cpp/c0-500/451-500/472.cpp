#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
private:
    // Check if word can be formed by concatenating other words
    bool canForm(string& word, int start, unordered_set<string>& wordSet, vector<int>& dp) {
        if (start == word.length()) return true;
        if (dp[start] != -1) return dp[start];
        
        string curr = "";
        for (int i = start; i < word.length(); i++) {
            curr += word[i];
            // If current substring is a word and remaining part can be formed
            if (wordSet.count(curr) && canForm(word, i + 1, wordSet, dp)) {
                dp[start] = 1;
                return true;
            }
        }
        
        dp[start] = 0;
        return false;
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // Put all words in a set for O(1) lookup
        unordered_set<string> wordSet(words.begin(), words.end());
        vector<string> result;
        
        for (string& word : words) {
            // Initialize dp array with -1 (unprocessed)
            vector<int> dp(word.length(), -1);
            
            // Temporarily remove current word from set
            wordSet.erase(word);
            
            // Check if word can be formed by concatenating at least 2 other words
            // Start from 0 and check if whole word can be formed
            if (word.length() > 0 && canForm(word, 0, wordSet, dp)) {
                result.push_back(word);
            }
            
            // Add word back to set
            wordSet.insert(word);
        }
        
        return result;
    }
};
Let's break down how this solution works:

Approach:
Use a hash set for O(1) word lookup
Use dynamic programming to check if a word can be formed by concatenation
For each word, check if it can be split into at least 2 valid subwords
canForm Function:
Parameters:
word: current word being checked
start: starting position in word
wordSet: set of all words
dp: memoization array
Returns true if substring from start to end can be formed by concatenation
Uses memoization to avoid redundant calculations
Tries all possible prefixes and checks if they're in wordSet
Main Algorithm:
Create set of all words
For each word:
Remove it from set (to avoid using itself as a single word)
Check if it can be formed by concatenation
Add it to result if valid
Put it back in set
Time Complexity:
For each word of length L:
canForm checks all prefixes: O(L²)
With memoization: O(L) states
Total: O(N * L) where N is number of words, L is max word length
Space Complexity: O(N) for hash set + O(L) for dp array
Example:
words = ["cat","cats","catsdogcats","dog","dogcatsdog"]
Check "catsdogcats":
Remove "catsdogcats" from set
Can split as "cats" + "dog" + "cats"
All parts in set → add to result
Result = ["catsdogcats", "dogcatsdog"]
Key Features:
Handles all constraints
Works with words of different lengths
Ensures at least 2 words in concatenation (by removing current word from set)
Efficient with memoization
Returns all valid concatenated words