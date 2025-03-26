class Solution {
    public:
        int magicalString(int n) {
            if(n == 0) return 0;
            if(n <= 3) return 1;
    
            string s = "122";
            int count = 1;
    
            int i = 2;
            char cur = '1';
    
            while(s.length() < n){
                int occurrences = s[i] - '0';
                i++;
    
                for(int j = 0; j < occurrences && s.length() < n; j++){
                    s += cur;
                    if(cur == '1') count++;
                }
                cur = (cur == '1') ? '2' : '1';
            }
            return count;
        }
    };