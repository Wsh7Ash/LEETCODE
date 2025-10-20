class Solution {
    public:
        int numWays(string s) {
            int n = s.length();
            const int MOD = 1e9+7;
    
            int ones = 0;
            for(char c : s){
                ones += (c == '1');
            }
            if(ones % 3 != 0) return 0;
            if(ones == 0){
                return (long long)(n-1)*(n-2) /2 % MOD;
            }
            int k = ones / 3;
            int count = 0;
            long long w1 = 0, w2 = 0;
            for(int i = 0; i < n; i++){
                count += (s[i] == '1');
                if(count == k) w1++;
                if(count == 2 * k) w2++;
            }
            return w1 * w2 % MOD;
        }
    };