class Solution {
    public:
        int minFlips(string target) {
            int n = target.length();
            int flips = 0;
            char cur = '0';
    
            for(int i = 0; i < n; i++){
                if(cur != target[i]){
                    flips++;
                    cur = (cur == '0') ? '1' : '0';
                }
            }
            return flips;
        }
    };