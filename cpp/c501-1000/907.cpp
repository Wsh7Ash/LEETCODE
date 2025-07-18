class Solution {
    public:
        int sumSubarrayMins(vector<int>& arr) {
           const int MOD = 1e9+ 7;
           int n = arr.size();
           vector<int> left(n), right(n);
           stack<pair<int, int>> s1, s2;
    
           for(int i = 0; i < n; i++){
            int cnt = 1;
            while(!s1.empty() && s1.top().first > arr[i]){
                cnt += s1.top().second;
                s1.pop();
            }
            s1.push({arr[i], cnt});
            left[i] = cnt;
           } 
    
           for(int i = n - 1; i >= 0; i--){
            int cnt = 1;
            while(!s2.empty() && s2.top().first >= arr[i]){
                cnt += s2.top().second;
                s2.pop();
            }
            s2.push({arr[i], cnt});
            right[i] = cnt;
           }
    
           long long res = 0;
           for(int i = 0; i < n; i++){
            res = (res + (long long)arr[i] * left[i] * right[i]) % MOD;
           }
           return res;
        }
    };