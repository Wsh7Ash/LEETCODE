class Solution {
    public:
        struct TrieNode{
            TrieNode* children[26];
            bool isRoot;
            TrieNode(){
                for(int i = 0; i < 26; i++){
                    children[i] = nullptr;
                }
                isRoot = false;
            }
        };
        TrieNode* root;
    
        void insertRoot(string& word){
            TrieNode* curr = root;
            for(char c : word){
                int idx = c - 'a';
                if(curr->children[idx] == nullptr){
                    curr->children[idx] = new TrieNode();
                }
                curr = curr->children[idx];
            }
            curr->isRoot = true;
        }
        string findShortestRoot(string& word){
            TrieNode* curr = root;
            string res = "";
            for(char c : word){
                int idx = c - 'a';
                if(curr->children[idx] == nullptr){
                    break;
                }
                curr = curr->children[idx];
                res += c;
                if(curr->isRoot){
                    return res;
                }
            }
            return word;
        }
        string replaceWords(vector<string>& dictionary, string sentence) {
            root = new TrieNode();
            for(string& rootWord : dictionary){
                insertRoot(rootWord);
            }
            string res = "";
            string curWord = "";
            for(int i = 0; i < sentence.length(); i++){
                if(sentence[i] == ' '){
                    if(!curWord.empty()){
                        if(!res.empty()){
                            res += " ";
                        }
                        res += findShortestRoot(curWord);
                        curWord = "";
                    }
                }else{
                    curWord += sentence[i];
                }
            }
            if(!curWord.empty()){
                if(!res.empty()){
                    res += " ";
                }
                res += findShortestRoot(curWord);
            }
            return res;
        }
    };