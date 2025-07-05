class Solution {
    public:
        int consecutiveNumbersSum(int n) {
            int c = 0;
            int mk = sqrt(2 * n) + 1;
            for(int k = 1; k <= mk; k++){
                int nume = n - k * ( k - 1) / 2;
                if(nume <= 0) break;
                if(nume % k == 0) c++;
            }
            return c;
        }
    };