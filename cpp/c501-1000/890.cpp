class Solution {
    public:
        vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
            vector<string> res;
            for(const string& word : words){
                if(matchesPattern(word, pattern)){
                    res.push_back(word);
                }
            }
            return res;
        }
    
        bool matchesPattern(const string& word, const string& pattern){
            if(word.length() != pattern.length()) return false;
    
            unordered_map<char, char> wtp;
            unordered_map<char, char> ptw;
    
            for(int i = 0; i < word.length(); i++){
                char w = word[i];
                char p = pattern[i];
    
                if(wtp.find(w) == wtp.end()){
                    wtp[w] = p;
                }else if(wtp[w] != p){
                    return false;
                }
    
                if(ptw.find(p) == ptw.end()){
                    ptw[p] = w;
                }else if(ptw[p] != w){
                    return false;
                }
            }
            return true;
        }
    };