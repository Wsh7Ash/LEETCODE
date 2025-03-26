class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // If endWord is not in the word list, no path can exist.
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        unordered_set<string> beginSet, endSet, tempSet; // Two sets for bidirectional BFS
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int steps = 1; // Start with step count 1 (including beginWord)

        // BFS loop, searching from both ends
        while (!beginSet.empty() && !endSet.empty()) {
            // Always expand the smaller set to optimize performance
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }

            tempSet.clear(); // Temporary set for the next level of BFS

            for (string word : beginSet) {
                string original = word; // Store the original word
                
                // Try changing each character of the word
                for (int i = 0; i < word.size(); i++) {
                    char ch = word[i]; // Store original character
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == ch) continue; // Skip same character
                        word[i] = c; // Modify character

                        // If the modified word is in the endSet, we found the shortest path
                        if (endSet.find(word) != endSet.end()) {
                            return steps + 1;
                        }

                        // If word exists in wordSet, add to tempSet and remove from wordSet
                        if (wordSet.find(word) != wordSet.end()) {
                            tempSet.insert(word);
                            wordSet.erase(word); // Remove from dictionary to prevent revisits
                        }
                    }
                    word[i] = ch; // Restore original character
                }
            }

            // Move to the next level in BFS
            swap(beginSet, tempSet);
            steps++;
        }
        
        // If no path is found, return 0
        return 0;
    }
};
