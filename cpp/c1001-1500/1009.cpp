class Solution {
    public:
        int bitwiseComplement(int n) {
            if(n == 0) return 1;
            int mask = 1;
            while(mask <= n){
                mask <<= 1;
            }
            return (mask - 1) ^ n;
        }
    };