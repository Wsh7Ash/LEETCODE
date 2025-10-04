class Solution {
    public:
        string freqAlphabets(string s) {
            string res = "";
            int i = 0;
    
            while(i < s.length()){
                if(i + 2 < s.length() && s[i + 2] == '#'){
                    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    res += char('a' + num - 1);
                    i+=3;
                }else{
                    int num = s[i] - '0';
                    res += char('a' + num - 1);
                    i+= 1;
                }
            }
            return res;
        }
    };