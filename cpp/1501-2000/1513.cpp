class Solution {
    public:
        int numSub(string s) {
            int MOD = 1e9+7;
            long long res = 0;
            int count = 0;
    
            for(char c : s){
                if(c =='1'){
                    count++;
                }else{
                    res = (res + (long long)count * (count + 1) / 2) % MOD;
                    count = 0;
                }
            }
            res = (res + (long long)count * (count + 1) / 2) % MOD;
            return res;
        }
    };