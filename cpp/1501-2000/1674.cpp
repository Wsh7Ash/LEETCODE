class Solution {
    public:
        int minMoves(vector<int>& nums, int limit) {
            int n = nums.size();
            vector<int> diff(2 * limit + 2, 0);
            for(int i  = 0; i < n / 2; i++){
                int a = nums[i];
                int b = nums[n - 1 - i];
                diff[2] += 2;
                diff[2 * limit + 1] -= 2;
                diff[min(a, b) + 1] -= 1;
                diff[max(a, b) + limit + 1] += 1;
                diff[a + b] -= 1;
                diff[a + b + 1] += 1;
    
            }
            int res = n;
            int cur = 0;
            for(int i = 2; i <= 2 * limit; i++){
                cur += diff[i];
                res = min(res, cur);
            }
            return res;
        }
    };