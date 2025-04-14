class Solution {
    public:
        bool checkRecord(string s) {
            int absentCount = 0;
            int consecutiveLate = 0;
    
            for(char c : s){
                if(c == 'A'){
                    absentCount++;
                    if(absentCount >= 2){
                        return false;
                    }
                    consecutiveLate = 0;
                }else if(c == 'L'){
                    consecutiveLate++;
                    if(consecutiveLate >= 3){
                        return false;
                    }
                }else{
                    consecutiveLate = 0;
                }
            }
            return true;
        }
    };