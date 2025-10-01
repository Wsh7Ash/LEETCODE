class Solution {
    public:
        int smallestDivisor(vector<int>& nums, int threshold) {
            int l = 1;
            int r = *max_element(nums.begin(), nums.end());
    
            while(l < r){
                int m = l + (r - l) / 2;
                if(cs(nums, m) <= threshold) r = m;
                else l = m + 1;
            }
            return l;
        }
    private:
        long long cs(vector<int>& nums, int divisor){
            long long sum = 0;
            for(int num : nums){
                sum += (num + divisor - 1) / divisor;
            }
            return sum;
        }
    };