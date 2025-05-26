class Solution {
    public:
        vector<int> constructArray(int n, int k) {
            vector<int> res;
            int l = 1, r = k+1;
            bool flag = true;
            for(int i = 0; i <= k; i++){
                if(flag){
                    res.push_back(l++);
                }
                else{
                    res.push_back(r--);
                }
                flag = !flag;
            }
            for(int i = k + 2; i <= n; i++){
                res.push_back(i);
            }
            return res;
        }
    };