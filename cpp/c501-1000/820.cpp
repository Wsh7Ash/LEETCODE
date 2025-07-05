class Solution {
    public:
        int minimumLengthEncoding(vector<string>& words) {
            unordered_set<string> uniqueWords(words.begin(), words.end());
            for(const string& word : words){
                for(int i = 1; i < word.size(); i++){
                    string suffix = word.substr(i);
                    if(uniqueWords.find(suffix) != uniqueWords.end()){
                        uniqueWords.erase(suffix);
                    }
                }
            }
            int l = 0;
            for(const string& word : uniqueWords){
                l += word.size() + 1;
            }
            return l;
        }
    };