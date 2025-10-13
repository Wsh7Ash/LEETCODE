class Solution {
    public:
        int maxPower(string s) {
            int maxLength = 1;
            int curLength = 1;
            for(int i = 1; i < s.length(); i++){
                if(s[i] == s[i -1]){
                    curLength++;
                    maxLength = max(maxLength, curLength);
                }else{
                    curLength = 1;
                }
            }
            return maxLength;
        }
    };