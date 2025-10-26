class Solution {
    public:
        int minimumDeletions(string s) {
            int countA = 0;
            int countB = 0;
    
            for(char c : s){
                if(c== 'a'){
                    countB = min(countA, countB) + 1;
                }else{
                    countB = min(countA, countB);
                    countA = countA + 1;
                }
            }
            return min(countA, countB);
        }
    };