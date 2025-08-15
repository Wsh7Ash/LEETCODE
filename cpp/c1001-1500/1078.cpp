class Solution {
    public:
        vector<string> findOcurrences(string text, string first, string second) {
            vector<string> res;
            vector<string> words;
            stringstream ss(text);
            string word;
            while(ss >> word){
                words.push_back(word);
            }
            for(int i = 0; i + 2 < words.size(); i++){
                if(words[i] == first && words[i + 1] == second){
                    res.push_back(words[i+2]);
                }
            }
            return res;
        }
    };