class Solution {
    public:
        int countPrimeSetBits(int left, int right) {
            vector<bool> is_prime = {false, false, true, true, false, true, false,
                                     true, false, false, false, true, false, true,
                                     false, false, false, true, false, true, false};
    
            int c = 0;
            for(int n = left; n <= right; n++){
                int sb = __builtin_popcount(n);
                if(sb < is_prime.size() && is_prime[sb]) c++;
            }
            return c;
        }
    };