class Solution {
    public:
        bool checkOnesSegment(string s) {
            bool foundZeroAfterOne = false;
            for(int i = 0; i < s.length(); i++){
                if(s[i] == '0'){
                    foundZeroAfterOne = true;
                }else if(s[i] == '1' && foundZeroAfterOne){
                    return false;
                }
            }
            return true;
        }
    };