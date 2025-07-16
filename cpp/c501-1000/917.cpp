class Solution {
    public:
        string reverseOnlyLetters(string s) {
            vector<char> letters;
            for(char c : s){
               if(isalpha(c)){
                letters.push_back(c);
               } 
            }   
    
            reverse(letters.begin(), letters.end());
            int letterIndex = 0;
            for(char& c : s){
                if(isalpha(c)){
                    c = letters[letterIndex++];
                }
            }
            return s;
        }
    };