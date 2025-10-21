class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for(int len = 1; len <= n; len+=2){
            for(int start = 0; start + len <= n; start++){
                for(int i = start; i < start + len; i++){
                    total += arr[i];
                }
            }
        }
        return total;
    }
};