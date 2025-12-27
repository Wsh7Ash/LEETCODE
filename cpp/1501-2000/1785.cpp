class Solution {
    public:
        int minElements(vector<int>& nums, int limit, int goal) {
            long long  sum = 0;
            for(int num : nums){
                sum += num;
            }
            long long diff = abs((long long)goal - sum);
            if(diff == 0) return 0;
            return (diff + limit - 1) / limit;
        }
    };