class Solution {
    public:
        int countHomogenous(string s) {
            int mod = 1e9+7;
            long long res = 0;
            int n = s.length();
    
            for(int i = 0; i < n; i++){
                long long count = 1;
                while(i + 1 < n && s[i] == s[i + 1]){
                    count++;
                    i++;
                }
                res = (res + (count * (count + 1)) / 2) % mod;
            }
            return (int)res;
        }
    };