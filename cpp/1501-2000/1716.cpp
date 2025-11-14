class Solution {
    public:
        int totalMoney(int n) {
            int total = 0;
            int weeks = n / 7;
            int days  = n % 7;
            if(weeks > 0){
                total += weeks * ( 7 * weeks + 49) / 2;
            }
            total += days * (2 * weeks + 1 + days) / 2;
            return total;
        }
    };