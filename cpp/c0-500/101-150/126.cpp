#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        if (wordSet.find(endWord) == wordSet.end()) {
            return result;  // If endWord is not in wordList, no solution
        }

        unordered_map<string, vector<string>> parents;  // Map to store parent nodes
        unordered_set<string> visited;
        visited.insert(beginWord);

        queue<string> q;
        q.push(beginWord);
        bool found = false;

        // BFS to find the shortest transformation paths
        while (!q.empty() && !found) {
            unordered_set<string> levelVisited;  // To track visited nodes at the current level
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                string word = q.front();
                q.pop();
                
                // Try all possible transformations
                for (int j = 0; j < word.length(); j++) {
                    char originalChar = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        word[j] = c;
                        
                        // If we reach the endWord, stop BFS and backtrack
                        if (word == endWord) {
                            found = true;
                        }
                        
                        if (wordSet.find(word) != wordSet.end() && visited.find(word) == visited.end()) {
                            if (!found) {
                                q.push(word);  // Enqueue the word
                            }
                            parents[word].push_back(q.front());  // Record the parent (previous word)
                            levelVisited.insert(word);  // Mark this word as visited for the current level
                        }
                    }
                    word[j] = originalChar;  // Restore the original character
                }
            }
            
            // Mark all the words visited in this level as visited
            for (const string& word : levelVisited) {
                visited.insert(word);
            }
        }

        // Backtrack to find all paths
        vector<string> path = {beginWord};
        backtrack(beginWord, endWord, parents, path, result);
        
        return result;
    }

private:
    // Helper function to backtrack and find all paths
    void backtrack(const string& current, 
                    const string& endWord,
                    unordered_map<string, vector<string>>& parents,
                    vector<string>& path,
                    vector<vector<string>>& result) {

        if (current == endWord) {
            result.push_back(vector<string>(path.rbegin(), path.rend()));  // Add the path in reverse order
            return;
        }

        for (const string& parent : parents[current]) {
            path.push_back(parent);
            backtrack(parent, endWord, parents, path, result);
            path.pop_back();  // Backtrack
        }
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);

    for (const auto& path : result) {
        for (const auto& word : path) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
