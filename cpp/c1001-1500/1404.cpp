class Solution {
    public:
        int numSteps(string s) {
            int steps = 0;
            int carry = 0;
            int n = s.length();
    
            for(int i = n - 1; i > 0; i--){
                if((s[i] - '0' + carry) % 2 == 1){
                    steps += 2;
                    carry = 1;
                }else{
                    steps += 1;
                }
            }
            return steps + carry;
        }
    };