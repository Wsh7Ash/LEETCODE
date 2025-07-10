class Solution {
    public:
        string decodeAtIndex(string s, int k) {
            long long size = 0;
            int n = s.size();
    
            for(char c : s){
                if(isdigit(c)){
                    size *= (c - '0');
                }else{
                    size++;
                }
            }
    
            for(int i = n - 1; i >= 0;i--){
                char c = s[i];
                k %= size;
                if(k == 0 && isalpha(c)){
                    return string(1, c);
                }
                if(isdigit(c)){
                    size /= (c - '0');
                }else{
                    size--;
                }
            }
            return "";
        }
    };