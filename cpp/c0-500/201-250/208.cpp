#include <iostream>
#include <unordered_map>
using namespace std;

class Trie {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd;  // Flag to mark the end of a word

        TrieNode() : isEnd(false) {}
    };
    
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();  // Initialize the root node
    }
    
    // Insert a word into the trie
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;  // Mark the end of the word
    }
    
    // Search for a word in the trie
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;  // Character not found, so the word is not in the trie
            }
            node = node->children[c];
        }
        return node->isEnd;  // Check if we are at the end of the word
    }
    
    // Check if there is any word in the trie that starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;  // Prefix not found
            }
            node = node->children[c];
        }
        return true;  // The prefix exists
    }
};

// Example usage:
int main() {
    Trie trie;
    
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // Output: 1 (True)
    cout << trie.search("app") << endl;     // Output: 0 (False)
    cout << trie.startsWith("app") << endl; // Output: 1 (True)
    
    trie.insert("app");
    cout << trie.search("app") << endl;    // Output: 1 (True)
    
    return 0;
}
