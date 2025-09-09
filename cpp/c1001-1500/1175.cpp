class Solution {
    public:
        const int MOD = 1000000007; 
        bool isPrime(int n){
            if(n <= 1) return false;
            for(int i =2; i * i <= n; i++){
                if(n % i == 0) return false;
            }
            return true;
    
        }
    
        int numPrimeArrangements(int n) {
            int primeCount = 0;
            for(int i = 1; i <= n; i++){
                if(isPrime(i)){
                    primeCount++;
                }
            }
    
            long long res = 1;
            for(int i = 1; i <= primeCount; i++){
                res = (res * i) % MOD;
            }
            for(int i = 1; i <= (n - primeCount); i++){
                res = (res * i) % MOD;
            }
            return res;
        }
    };