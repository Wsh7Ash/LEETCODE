class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            double cur_sum = 0;
            for(int i = 0; i < k; i++){
                cur_sum += nums[i];
            }
            double max_sum = cur_sum;
            for(int i = k; i < nums.size(); i++){
                cur_sum += nums[i] - nums[i - k];
                max_sum = max(max_sum, cur_sum);
            }
            return max_sum/k;
        }
    };