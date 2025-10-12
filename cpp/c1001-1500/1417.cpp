class Solution {
    public:
        string reformat(string s) {
            string letters, digits;
    
            for(char c : s){
                if(isalpha(c)) letters += c;
                else digits += c;
            }
    
            if(abs((int)letters.length() - (int)digits.length()) > 1) return "";
    
            if(letters.length() < digits.length()) swap(letters, digits);
    
            string res;
            for(int i = 0; i < letters.length(); i++){
                res += letters[i];
                if(i < digits.length()){
                    res += digits[i];
                }
            }
    
            return res;
        }
    };