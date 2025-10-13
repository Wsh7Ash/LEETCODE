class Solution {
    public:
        string arrangeWords(string text) {
            text[0] = tolower(text[0]);
    
            vector<string> words;
            stringstream ss(text);
            string word;
    
            while(ss >> word){
                words.push_back(word);
            }
    
            stable_sort(words.begin(), words.end(), [](const string& a, const string& b){
                return a.length() < b.length();
            });
    
            if(!words.empty()){
                words[0][0] = toupper(words[0][0]);
            }
    
            string res;
            for(int i = 0; i < words.size(); i++){
                if(i > 0){
                    res += " ";
                }
                res += words[i];
            }
    
            return res;
        }
    };