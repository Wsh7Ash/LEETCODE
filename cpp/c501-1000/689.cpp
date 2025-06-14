class Solution {
    public:
        vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> pf(n+1, 0);
            for(int i = 0; i < n; i++){
                pf[i + 1]   = pf[i] + nums[i];
            }
            vector<int> w(n - k + 1, 0);
            for(int i = 0; i <= n - k; i++){
                w[i] = pf[i + k] - pf[i];
            }
    
            vector<int> l(n - k + 1, 0);
            int b = 0;
            for(int i = 0; i <= n - k; i++){
                if(w[i] > w[b]){
                    b = i;
                }
                l[i] = b;
            }
    
            vector<int> r(n - k + 1, 0);
            b = n - k;
            for(int i = n - k; i >= 0;i-- ){
                if(w[i] >= w[b]){
                    b = i;
                }
                r[i] = b;
            }
    
            vector<int> res(3, -1);
            int ms = 0;
            for(int j = k; j <= n - 2 * k; j++){
                int i = l[j - k];
                int ll = r[j + k];
                int cs = w[i] + w[j] + w[ll];
                if(cs > ms){
                    ms = cs;
                    res = {i, j, ll};
                }
            }
            return res;
        }
    };