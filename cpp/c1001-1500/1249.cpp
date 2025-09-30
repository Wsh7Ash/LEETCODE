class Solution {
    public:
        string minRemoveToMakeValid(string s) {
            
            string temp = "";
            int openCount = 0;
    
            for(char c : s){
                if(c == '('){
                    temp += c;
                    openCount++;
                }else if(c == ')'){
                   if(openCount > 0){
                     temp += c;
                    openCount--;
                   }
                }
                else{
                    temp += c;
                }
            }
    
            string res = "";
            int openNeeded = 0;
    
            for(char c : temp){
                if(c == ')'){
                    openNeeded++;
                }
            }
    
            int openKept = 0;
            for(char c : temp){
                if(c == '('){
                    if(openKept < openNeeded){
                        res += c;
                        openKept++;
                    }
                }
                else{
                    res += c;
                }
            }
            return res;
        }
    };