bool wordPattern(string pattern, string s) {
    // Split string s into words
    vector<string> words;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    
    // Check if lengths match
    if (pattern.length() != words.size()) {
        return false;
    }
    
    // Map for char -> word
    unordered_map<char, string> charToWord;
    // Map for word -> char
    unordered_map<string, char> wordToChar;
    
    // Check mapping in both directions
    for (int i = 0; i < pattern.length(); i++) {
        char c = pattern[i];
        string w = words[i];
        
        // If char already mapped
        if (charToWord.count(c)) {
            // Check if it maps to same word
            if (charToWord[c] != w) {
                return false;
            }
        }
        // If char not mapped yet
        else {
            // Check if word is already mapped to different char
            if (wordToChar.count(w)) {
                return false;
            }
            // Create new mapping
            charToWord[c] = w;
            wordToChar[w] = c;
        }
    }
    
    return true;
}
Let's break down how this works:

Word Splitting:
Use stringstream to split the input string s into words
Store words in a vector
Initial Validation:
Check if pattern length matches number of words
If not, return false as no bijection is possible
Two-Way Mapping:
Use two hash maps:
charToWord: maps pattern chars to words
wordToChar: maps words to pattern chars
Ensures bijection (one-to-one correspondence)
Main Logic:
Iterate through pattern and words simultaneously
For each pair (c, w):
If c is already mapped:
Check if it maps to w
If not, return false
If c is not mapped:
Check if w is already mapped to another char
If yes, return false
If no, create new mapping in both directions
Example walkthrough with "abba" and "dog cat cat dog":

text
Wrap
Copy
i=0: 'a'->'dog' (new mapping)
i=1: 'b'->'cat' (new mapping)
i=2: 'b'->'cat' (matches existing)
i=3: 'a'->'dog' (matches existing)
Return true
Time Complexity: O(n) where n is length of pattern/number of words

Linear pass through the input
String splitting is O(n)
Space Complexity: O(n)

Space for word vector
Space for two hash maps
This solution:

Correctly handles all example cases
Ensures bijection property
Meets all constraints
Handles the mapping requirements efficiently
Returns false for invalid cases like different words mapping to same char or same word mapping to different chars