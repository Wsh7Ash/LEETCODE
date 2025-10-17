class Solution {
    public:
        string minInteger(string num, int k) {
            int n = num.size();
            if(k <= 0) return num;
    
            if(k >= n * (n - 1) / 2){
                sort(num.begin(), num.end());
                return num;
            }
    
            for(int i = 0; i < n && k > 0; i++){
                int bestPos = i;
                for(int j = i + 1; j < n && j - i <= k; j++){
                    if(num[j] < num[bestPos]){
                        bestPos = j;
                    }
                }
                if(bestPos != i){
                    char digit = num[bestPos];
                    for(int j = bestPos; j > i; j--){
                        num[j] = num[j - 1];
                    }
                    num[i] = digit;
                    k -= (bestPos - i);
                }
            }
            return num;
        }
    };