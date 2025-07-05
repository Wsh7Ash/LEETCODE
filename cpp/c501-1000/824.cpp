class Solution {
    public:
        string toGoatLatin(string sentence) {
            vector<string> words;
            string curWord;
            for(char c : sentence){
                if(c == ' '){
                    words.push_back(curWord);
                    curWord.clear();
                }else{
                    curWord += c;
                }
            }
            words.push_back(curWord);
    
            for(int i = 0; i < words.size(); i++){
                string& word = words[i];
                if(word.empty()) continue;
                char firstChar = tolower(word[0]);
                if(firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u'){
                    word += "ma";
                }else{
                    if(word.size() > 1){
                        word = word.substr(1) + word[0];
                    }
                    word += "ma";
                }
                word += string(i + 1, 'a');
            }
    
            string res;
            for(int i = 0; i < words.size(); i++){
                if(i != 0){
                    res += " ";
                }
                res += words[i];
            }
            return res;
        }
    };