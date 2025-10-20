class Solution {
    public:
        string modifyString(string s) {
            int n = s.size();
            for(int i = 0; i < n; i++){
                if(s[i] == '?'){
                    char l = (i == 0) ? ' ' : s[i-1];
                    char r = (i == n - 1) ? ' ' : s[i + 1];
                    for(char c = 'a'; c <= 'z'; c++){
                        if(c != l && c != r){
                            s[i] = c;
                            break;
                        }
                    }
                }
            }
            return s;
        }
    };