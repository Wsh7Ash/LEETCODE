class WordFilter {
    public:
        unordered_map<string, int> dict;
        WordFilter(vector<string>& words) {
            for(int index = 0; index < words.size(); index++){
                string word = words[index];
                int wordSize = word.size();
                for(int i = 0; i <= wordSize; i++){
                    string prefix = word.substr(0, i);
                    for(int j = 0; j <= wordSize; j++){
                        string suffix = word.substr(j);
                        string key = prefix + "#" + suffix;
                        dict[key] = index;
                    }
                }
            }
        }
        
        int f(string pref, string suff) {
            string key = pref + "#" + suff;
            if(dict.find(key) != dict.end()) return dict[key];
            return -1;
        }
    };
    
    /**
     * Your WordFilter object will be instantiated and called as such:
     * WordFilter* obj = new WordFilter(words);
     * int param_1 = obj->f(pref,suff);
     */