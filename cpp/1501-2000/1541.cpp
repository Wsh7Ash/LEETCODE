class Solution {
    public:
        int minInsertions(string s) {
            int insertions = 0;
            int needed = 0;
    
            for(int i = 0; i < s.length(); i++){
                if(s[i] == '('){
                    needed+=2;
                    if(needed % 2 == 1){
                        insertions++;
                        needed--;
                    }
                }else{
                    needed--;
                    if(needed < 0){
                        insertions++;
                        needed += 2;
                    }
                }
            }
            return insertions + needed;
        }
    };