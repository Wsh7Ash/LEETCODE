class WordDictionary {
    private:
        // Trie node structure
        struct TrieNode {
            bool isEnd;                     // Marks if this node ends a word
            vector<TrieNode*> children;     // Children nodes for each letter (26 letters)
            
            TrieNode() : isEnd(false) {
                children.resize(26, nullptr);  // Initialize with 26 null pointers
            }
        };
        
        TrieNode* root;  // Root of the Trie
        
        // Helper function for recursive search with dots
        bool searchHelper(string& word, int index, TrieNode* node) {
            // Base case: reached end of word
            if (index == word.length()) {
                return node->isEnd;
            }
            
            // If current character is a dot
            if (word[index] == '.') {
                // Try all possible letters (children)
                for (TrieNode* child : node->children) {
                    if (child != nullptr && searchHelper(word, index + 1, child)) {
                        return true;
                    }
                }
                return false;
            }
            
            // If current character is a letter
            int charIndex = word[index] - 'a';
            if (node->children[charIndex] == nullptr) {
                return false;
            }
            return searchHelper(word, index + 1, node->children[charIndex]);
        }
    
    public:
        WordDictionary() {
            root = new TrieNode();
        }
        
        void addWord(string word) {
            TrieNode* curr = root;
            // Iterate through each character in the word
            for (char c : word) {
                int index = c - 'a';
                // If no node exists for this character, create one
                if (curr->children[index] == nullptr) {
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
            }
            // Mark the end of the word
            curr->isEnd = true;
        }
        
        bool search(string word) {
            return searchHelper(word, 0, root);
        }
    };
    
    /**
     * Your WordDictionary object will be instantiated and called as such:
     * WordDictionary* obj = new WordDictionary();
     * obj->addWord(word);
     * bool param_2 = obj->search(word);
     */