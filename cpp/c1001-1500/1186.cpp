class Solution {
    public:
        int maximumSum(vector<int>& arr) {
            int n = arr.size();
            if(n == 1) return arr[0];
    
            int dp0 = arr[0];
            int dp1 = 0;
            int res = arr[0];
    
            for(int i = 1; i < n; i++){
                dp1 = max(dp0, dp1 + arr[i]);
                dp0 = max(arr[i], dp0 + arr[i]);
                res = max({res, dp0, dp1});
            }
    
            return res;
        }
    };class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];

        int dp0 = arr[0];
        int dp1 = 0;
        int res = arr[0];

        for(int i = 1; i < n; i++){
            dp1 = max(dp0, dp1 + arr[i]);
            dp0 = max(arr[i], dp0 + arr[i]);
            res = max({res, dp0, dp1});
        }

        return res;
    }
};