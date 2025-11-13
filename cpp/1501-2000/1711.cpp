class Solution {
    public:
        int countPairs(vector<int>& deliciousness) {
            int mod = 1e9+7;
            map<int, int> freq;
            long long res = 0;
            vector<int> powers;
            for(int i = 0; i <= 21; i++){
                powers.push_back(1 << i);
            }
            for(int d : deliciousness){
                for(int p : powers){
                    int comp = p - d;
                    if(freq.count(comp)){
                        res = (res + freq[comp]) % mod;
                    }
                }
                freq[d]++;
            }
            return res;
        }
    };