class Solution {
    public:
        string longestWord(vector<string>& words) {
            sort(words.begin(), words.end());
            unordered_set<string> builtWords;
            string res;
    
            for(const string& word : words){
                if(word.size() == 1 || builtWords.count(word.substr(0, word.size() - 1))){
                    if(word.size() > res.size()){
                        res = word;
                    }
                    builtWords.insert(word);
                }
            }
            return res;
            
        }
    };