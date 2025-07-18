class Solution {
    public:
        int minFlipsMonoIncr(string s) {
            int n = s.size();
    
            vector<int> prefixOnes(n+1, 0);
            vector<int> suffixZeros(n+1, 0);
    
            for(int i = 1; i <= n; i++){
                prefixOnes[i] = prefixOnes[i-1] + (s[i-1] == '1' ? 1 : 0);
            }
            for(int i = n - 1; i >= 0; i--){
                suffixZeros[i] = suffixZeros[i+1] + (s[i] == '0' ? 1 : 0);
            }
    
            int minFlips = INT_MAX;
            for(int  i = 0; i <= n; i++){
                minFlips = min(minFlips, prefixOnes[i] + suffixZeros[i]);
            }
            return minFlips;
    
        }
    };