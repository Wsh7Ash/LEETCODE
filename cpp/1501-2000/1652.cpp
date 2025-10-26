class Solution {
    public:
        vector<int> decrypt(vector<int>& code, int k) {
            int n = code.size();
            vector<int> res(n, 0);
            if(k == 0) return res;
            if(k > 0){
                for(int i = 0; i < n; i++){
                    int sum = 0;
                    for(int j = 1; j <= k; j++){
                        sum += code[(i + j) % n];
                    }
                    res[i] = sum;
                }
            }else{
                k = -k;
                for(int i = 0; i < n; i++){
                    int sum = 0;
                    for(int j = 1; j <= k; j++){
                        sum += code[(i - j + n) % n];
                    }
                    res[i] = sum;
                }
            }
            return res;
        }
    };