class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int MOD = 1e9+7;
            int n = arr.size();
            int evenPrefix = 1, oddPrefix = 0;
            int prefixSum = 0;
            long long count = 0;
    
            for(int num : arr){
                prefixSum = (prefixSum + num) % 2;
                if(prefixSum == 1){
                    count = (count + evenPrefix) % MOD;
                    oddPrefix++;
                }else{
                    count = (count + oddPrefix) % MOD;
                    evenPrefix++;
                }
            }
            return count;
        }
    };