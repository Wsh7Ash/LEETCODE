class Solution {
    public:
        int maxDepth(string s) {
            int curDepth = 0;
            int maxDepth = 0;
    
            for(char c : s){
                if(c == '('){
                    curDepth++;
                    maxDepth = max(maxDepth, curDepth);
                }
                else if(c == ')'){
                    curDepth--;
                }
            }
            return maxDepth;
        }
    };