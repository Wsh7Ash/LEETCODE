class Solution {
    public:
        int concatenatedBinary(int n) {
            int mod = 1e9+7;
            long long res = 0;
            int bitlen = 0;
            for(int i = 1; i <= n; i++){
                if((i & (i - 1)) == 0)bitlen++;
                res = ((res << bitlen) + i) % mod;
            }
            return (int)res;
        }
    };