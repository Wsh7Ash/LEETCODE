class Solution {
    public:
        vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
            int n = candiesCount.size();
            vector<long long> prefixSum(n + 1, 0);
            for(int i= 0; i < n; i++){
                prefixSum[i + 1] = prefixSum[i] + candiesCount[i];
            }
            vector<bool> res(queries.size());
            for(int i = 0; i < queries.size(); i++){
                int favType = queries[i][0];
                long long favDay = queries[i][1];
                long long dailyCap = queries[i][2];
                long long candiesBefore = prefixSum[favType];
                long long candiesUpToFav = prefixSum[favType + 1];
                res[i] = (favDay < candiesUpToFav) && ((favDay + 1) * dailyCap > candiesBefore);
            }
            return res;
        }
    };