class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefix(n + 1,0);
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }   

        int maxSum = 0;

        int mf = 0;

        for(int i = firstLen; i <= n - secondLen; i++){
            int curF = prefix[i] - prefix[i - firstLen];
            mf = max(mf, curF);
            int curS = prefix[i + secondLen] - prefix[i];
            maxSum = max(maxSum, mf + curS); 
        }

        int ms = 0;
        for(int i = secondLen; i <= n - firstLen; i++){
            int curS = prefix[i] - prefix[i - secondLen];
            ms = max(ms, curS);
            int curF = prefix[i + firstLen] - prefix[i];
            maxSum = max(maxSum, ms + curF);
        }

        return maxSum;
    }
};