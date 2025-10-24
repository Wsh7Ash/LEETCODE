class Fancy {
    public:
        const int mod = 1e9+7;
        vector<long long> values;
        long long a,b;
        vector<long long> inv;
        
        long long modPow(long long base, long long exp){
            long long res = 1;
            while(exp > 0){
                if(exp & 1) res = (res * base) % mod;
                base = (base * base) % mod;
                exp >>= 1;
            }
            return res;
        } 
    
        long long getInverse(long long x) {
            if (x < inv.size()) {
                return inv[x];
            }
            // Compute inverse on-demand for values beyond precomputed range
            return modPow(x, mod - 2);
        }
    
        void precomputeInverses(){
            inv.resize(101);
            for(int i = 1; i <= 100; i++){
                inv[i] = modPow(i, mod - 2);
            }
        }
    
        Fancy() {
            precomputeInverses();
            a = 1;
            b = 0;
        }
        
        void append(int val) {
            long long inverse_a = getInverse(a);
            long long raw = ((val - b + mod) % mod * inverse_a) % mod;
            values.push_back(raw);
        }   
        
        void addAll(int inc) {
            b = (b + inc) % mod;
        }
        
        void multAll(int m) {
            a = (a * m) % mod;
            b = (b * m) % mod;
        }
        
        int getIndex(int idx) {
            if(idx >= values.size()) return -1;
            return (a * values[idx] + b) % mod;
        }
    };