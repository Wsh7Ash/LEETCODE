class MagicDictionary {
    public:
        vector<string> dict;
        MagicDictionary() {
            
        }
        
        void buildDict(vector<string> dictionary) {
            dict =   dictionary;      
        }
        
        bool search(string searchWord) {
            for(string& word : dict){
                if(word.length() != searchWord.length()){
                    continue;
                }
                int diff = 0;
                for(int i = 0; i < word.length(); i++){
                    if(word[i] != searchWord[i]){
                        diff++;
                        if(diff > 1){
                            break;
                        }
                    }
                }
                if(diff == 1){
                    return true;
                }
            }
            return false;
        }
    };
    
    /**
     * Your MagicDictionary object will be instantiated and called as such:
     * MagicDictionary* obj = new MagicDictionary();
     * obj->buildDict(dictionary);
     * bool param_2 = obj->search(searchWord);
     */