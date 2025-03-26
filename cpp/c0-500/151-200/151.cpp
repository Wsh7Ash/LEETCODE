#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Trim leading and trailing spaces
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);

        // Step 2: Split into words
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        // Step 3: Reverse the words
        reverse(words.begin(), words.end());

        // Step 4: Join the words with a single space
        string result;
        for (size_t i = 0; i < words.size(); ++i) {
            if (i != 0) {
                result += ' ';
            }
            result += words[i];
        }

        return result;
    }
};