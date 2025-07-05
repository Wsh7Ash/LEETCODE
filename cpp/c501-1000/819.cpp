class Solution {
    public:
        string mostCommonWord(string paragraph, vector<string>& banned) {
            unordered_set<string> bannedSet(banned.begin(), banned.end());
            unordered_map<string, int> wordCount;
    
            string processed;
            for(char c : paragraph){
                if(isalpha(c)){
                    processed += tolower(c);
                }else{
                    processed += ' ';
                }
            }
    
            vector<string> words;
            string word;
            for(char c : processed){
                if(isalpha(c)){
                    word += c;
                }else{
                    if(!word.empty()){
                        words.push_back(word);
                        word.clear();
                    }
                }
            }
            if(!word.empty()){
                words.push_back(word);
            }
    
            for(const string& w : words){
                if(bannedSet.find(w) == bannedSet.end()){
                    wordCount[w]++;
                }
            }
            string res;
            int maxCount = 0;
            for(const auto& pair : wordCount){
                if(pair.second > maxCount){
                    maxCount = pair.second;
                    res = pair.first;
                }
            }
            return res;
        }
    };