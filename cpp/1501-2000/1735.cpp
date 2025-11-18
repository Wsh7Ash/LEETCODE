class Solution {
    public:
        static const int mod = 1e9+7;
        static const int MAX_N = 10000;
        static const int MAX_K = 10000;
        vector<long long> fact;
        vector<long long> inv_fact;
        void precompute(){
            int max_val = MAX_N + MAX_K;
            fact.resize(max_val + 1);
            inv_fact.resize(max_val + 1);
            fact[0] = 1;
            for(int i = 1; i <= max_val; i++){
                fact[i] = (fact[i - 1] * i) % mod;
            }
            inv_fact[max_val] = modInverse(fact[max_val], mod);
            for(int i = max_val - 1; i >= 0; i--){
                inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
            }
        }
    
        long long modInverse(long long a, long long mod){
            return power(a, mod - 2, mod);
        }
    
        long long power(long long base, long long exp, long long mod){
            long long res = 1;
            while(exp > 0){
                if(exp & 1){
                    res = (res * base) % mod;
                }
                base = (base * base) % mod;
                exp >>= 1;
            }
            return res;
        }
    
        long long comb(int n, int r){
            if(r > n || r < 0) return 0;
            return (fact[n] * inv_fact[r] % mod) * inv_fact[n - r] % mod;
        }
    
        map<int, int> primeFactorize(int n){
            map<int, int> factors;
            int d = 2;
            while(d * d <= n){
                while(n % d == 0){
                    factors[d]++;
                    n /= d;
                }
                d++;
            }
            if(n > 1) factors[n]++;
            return factors;
        }
    
        vector<int> waysToFillArray(vector<vector<int>>& queries) {
            precompute();
            vector<int> res;
            for(const auto& query : queries){
                int n = query[0];
                int k = query[1];
                map<int, int> prime_factors = primeFactorize(k);
                long long ways = 1;
                for(const auto& factor : prime_factors){
                    int prime = factor.first;
                    int power = factor.second;
                    ways = (ways * comb(n + power - 1, power)) % mod;
                }
                res.push_back((int)ways);
            }
            return res;
        }
    };