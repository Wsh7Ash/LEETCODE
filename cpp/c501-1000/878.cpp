class Solution {
    public:
        const int MOD = 1e9 + 7;
        int nthMagicalNumber(int n, int a, int b) {
            long long l = 1;
            long long h = 1e18;
            int lcm_ab = (a / __gcd(a,b))* b;
    
            while(l < h){
                long long m = l + (h - l) / 2;
                long long count = m / a + m / b - m / lcm_ab;
    
                if(count < n){
                    l = m + 1;
                }else{ 
                    h = m;
                }
            }
            return l % MOD;
        }
    };