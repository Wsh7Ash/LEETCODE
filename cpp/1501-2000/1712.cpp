class Solution {
    public:
        int waysToSplit(vector<int>& nums) {
           int mod = 1e9+7;
           int n = nums.size();
           vector<int> prefix(n+1, 0);
           for(int i = 0; i < n; i++){
                prefix[i + 1] = prefix[i] + nums[i];
           } 
           long long res = 0;
           int j = 1, k = 1;
           for(int i = 1; i <= n; i++){
            int leftSum = prefix[i];
            j = max(j, i + 1);
            while(j <= n - 1 && prefix[j] - prefix[i] < leftSum){
                j++;
            }
            k = max(k, j);
            while(k <= n - 1 && prefix[n] - prefix[k] >= prefix[k]  - prefix[i]){
                k++;
            }
            if(j <= n - 1 && k > j){
                res = (res + (k - j)) % mod;
            }
           }
           return res;
        }
    };