class Solution {
    public:
        string convertToBase7(int num) {
            if (num == 0) return "0";
    
            bool isNegative = num < 0;
            num = abs(num);
            string res;
    
            while(num > 0){
                int rem = num % 7;
                res.push_back(rem + '0');
                num /= 7;
            }
            if(isNegative){
                res.push_back('-');
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };