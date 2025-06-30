class Solution {
    public:
        int rotatedDigits(int n) {
            int c = 0;
            for(int i = 1; i <= n; i++){
                if(isGood(i)){
                    c++;
                }
            }
            return c;
        }
    
        bool isGood(int num){
            bool validFound = false;
            while(num > 0){
                int digit = num % 10;
                if(digit == 3 || digit == 4 || digit == 7) return false;
                if(digit == 2 || digit == 5 || digit == 6 || digit == 9) validFound =  true;
                num /= 10;
            }
            return validFound;
        }
    };