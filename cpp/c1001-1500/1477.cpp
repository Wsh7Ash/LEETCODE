class Solution {
    public:
        int minSumOfLengths(vector<int>& arr, int target) {
            int n = arr.size();
            int INF = 1e9;
    
            vector<int> minlen(n, INF);
    
            unordered_map<int, int> prefixSum;
            prefixSum[0] = -1;
            int sum = 0;
            int res = INF;
            int b = INF;
    
            for(int i = 0; i < n; i++){
                sum += arr[i];
                if(prefixSum.find(sum - target) != prefixSum.end()){
                    int start = prefixSum[sum - target] + 1;
                    int curlen = i - start + 1;
                    if(start > 0 && minlen[start - 1] != INF){
                        res = min(res, curlen + minlen[start - 1]);
                    }
                    b = min(b, curlen);
                }
                minlen[i] = b;
                prefixSum[sum] = i;
            }
            return res == INF ? -1 : res;
        }
    };