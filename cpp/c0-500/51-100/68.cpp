#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index = 0;

        while (index < n) {
            // Step 1: Determine the words that can fit in the current line
            int totalChars = words[index].length(); // Total characters in the current line
            int last = index + 1; // Index of the last word that can fit in the current line

            // Add words to the line until we can't fit any more
            while (last < n) {
                if (totalChars + 1 + words[last].length() > maxWidth) break;
                totalChars += 1 + words[last].length(); // Add space and the word's length
                last++;
            }

            // Step 2: Calculate the number of words and spaces in the current line
            int numWords = last - index; // Number of words in the current line
            int numSpaces = maxWidth - totalChars + (numWords - 1); // Total spaces needed

            // Step 3: Build the justified line
            string line;

            // Case 1: Only one word or last line (left-justified)
            if (numWords == 1 || last == n) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " "; // Add a single space between words
                }
                // Add remaining spaces to the end
                line += string(maxWidth - line.length(), ' ');
            }
            // Case 2: Fully justified line
            else {
                int spacePerWord = numSpaces / (numWords - 1); // Base spaces per word
                int extraSpaces = numSpaces % (numWords - 1); // Extra spaces to distribute

                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        // Add base spaces
                        line += string(spacePerWord, ' ');
                        // Add extra spaces (if any)
                        if (extraSpaces > 0) {
                            line += " ";
                            extraSpaces--;
                        }
                    }
                }
            }

            // Step 4: Add the line to the result
            result.push_back(line);
            index = last; // Move to the next set of words
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth1 = 16;
    vector<string> result1 = solution.fullJustify(words1, maxWidth1);
    for (const string& line : result1) {
        cout << "\"" << line << "\"" << endl;
    }

    vector<string> words2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int maxWidth2 = 16;
    vector<string> result2 = solution.fullJustify(words2, maxWidth2);
    for (const string& line : result2) {
        cout << "\"" << line << "\"" << endl;
    }

    vector<string> words3 = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int maxWidth3 = 20;
    vector<string> result3 = solution.fullJustify(words3, maxWidth3);
    for (const string& line : result3) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}