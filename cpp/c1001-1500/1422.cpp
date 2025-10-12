class Solution {
    public:
        int maxScore(string s) {
            int n = s.length();
    
            int totalOnes = 0;
            for(char c : s){
                if(c == '1') totalOnes++;
            }
    
            int maxScore = 0;
            int zeros = 0;
            int ones = 0;
    
            for(int i = 0; i < n - 1; i++){
                if(s[i] == '0'){
                    zeros++;
                }else{
                    ones++;
                }
    
                int curScore = zeros + (totalOnes - ones);
                maxScore = max(maxScore, curScore);
            }
    
            return maxScore;
        }
    };