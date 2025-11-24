class Solution {
    public:
        string longestNiceSubstring(string s) {
            if(s.length() < 2) return "";
            set<char> chars(s.begin(), s.end());
    
            for(int i = 0; i < s.length(); i++){
                char c = s[i];
                if(chars.find(toupper(c)) == chars.end() || chars.find(tolower(c)) == chars.end()){
                    string left = longestNiceSubstring(s.substr(0, i));
                    string right = longestNiceSubstring(s.substr(i+1));
                    return left.length() >= right.length() ? left : right;
                }
            }
            return s;
        }
    };