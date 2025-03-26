class Solution {
    private:
        // Trie Node structure
        struct TrieNode {
            TrieNode* children[26];
            string word;  // Store the complete word at leaf
            TrieNode() : word("") {
                for (int i = 0; i < 26; i++) {
                    children[i] = nullptr;
                }
            }
        };
        
        // Build Trie from words list
        TrieNode* buildTrie(vector<string>& words) {
            TrieNode* root = new TrieNode();
            for (string& word : words) {
                TrieNode* curr = root;
                for (char c : word) {
                    int idx = c - 'a';
                    if (!curr->children[idx]) {
                        curr->children[idx] = new TrieNode();
                    }
                    curr = curr->children[idx];
                }
                curr->word = word;  // Store word at the end
            }
            return root;
        }
        
        void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, 
                 vector<string>& result) {
            // Check bounds and if current cell is valid
            if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || 
                board[i][j] == '#') {
                return;
            }
            
            char currChar = board[i][j];
            TrieNode* nextNode = node->children[currChar - 'a'];
            
            // If no path in Trie, return
            if (!nextNode) return;
            
            // If we found a word
            if (!nextNode->word.empty()) {
                result.push_back(nextNode->word);
                nextNode->word = "";  // Mark as used to avoid duplicates
            }
            
            // Mark current cell as visited
            board[i][j] = '#';
            
            // Explore all four directions
            dfs(board, i+1, j, nextNode, result);  // down
            dfs(board, i-1, j, nextNode, result);  // up
            dfs(board, i, j+1, nextNode, result);  // right
            dfs(board, i, j-1, nextNode, result);  // left
            
            // Restore cell for other paths
            board[i][j] = currChar;
        }
        
    public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            vector<string> result;
            TrieNode* root = buildTrie(words);
            
            // Start DFS from each cell
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    dfs(board, i, j, root, result);
                }
            }
            
            return result;
        }
    };