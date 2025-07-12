class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long> pow2(n);
        pow2[0] = 1;
        for(int i = 1; i < n; i++){
            pow2[i] = (pow2[i-1] * 2) % MOD;
        }

        long res = 0;
        for(int i = 0; i < n; i++){
            long left = pow2[i];
            long right = pow2[n-1-i];
            res = (res + nums[i] * (left - right)) % MOD;
        }
        return (res % MOD + MOD) % MOD;
    }
};