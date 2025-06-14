class Solution {
    public:
        bool checkValidString(string s) {
            int mo = 0;
            int mmo = 0;
            for(char c : s){
                if(c == '('){
                    mo++;
                    mmo++;
                }else if(c == ')'){
                    mo = max(mo - 1, 0);
                    mmo--;
                    if(mmo < 0) return false;
                }else{
                    mo = max(mo -1, 0);
                    mmo++;
                }
            }
            return mo == 0;
        }
    };