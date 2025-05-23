class Solution {
    public:
        vector<int> findErrorNums(vector<int>& nums) {
            vector<int> res(2);
            unordered_set<int> seen;
            int n = nums.size();
            int expected_num = n*(n+1)/2;
            int actual_sum = 0;
            for(int num : nums){
                if(seen.count(num)){
                    res[0] = num;
                }
                seen.insert(num);
                actual_sum += num;
            }
            res[1] = expected_num - (actual_sum - res[0]);
            return res;
        }
    };