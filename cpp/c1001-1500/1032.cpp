class TrieNode{
    public:
        vector<TrieNode*> children;
        bool isEnd;
        TrieNode() : children(26, nullptr) , isEnd(false) {}
    };
    
    class StreamChecker {
    private:
        TrieNode* root;
        vector<char> stream;
    
        void insertReverse(const string& word){
            TrieNode* node = root;
            for(int i = word.size() - 1; i >= 0; i--){
                char c = word[i];
                int index = c - 'a';
                if(node->children[index] == nullptr) node->children[index] = new TrieNode();
                node = node->children[index];
            }
            node->isEnd = true;
        }
    
    public:
        StreamChecker(vector<string>& words) {
            root = new TrieNode();
            for(const string& word : words){
                insertReverse(word);
            }
        }
        
        bool query(char letter) {
            
            stream.push_back(letter);
            TrieNode* node = root;
            for(int i = stream.size() - 1; i >= 0; i--){
                char c = stream[i];
                int index = c - 'a';
                if(node->children[index] == nullptr) return false;
                node = node->children[index];
                if(node->isEnd) return true;
            }
            return false;
        }
    };
    
    /**
     * Your StreamChecker object will be instantiated and called as such:
     * StreamChecker* obj = new StreamChecker(words);
     * bool param_1 = obj->query(letter);
     */