class Solution {
    public:
        vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
            int evenSum = 0;
            for(int num : nums){
                if(num % 2 == 0){
                    evenSum += num;
                }
            }
    
            vector<int> ans;
            for(const auto& query : queries){
                int val = query[0];
                int idx = query[1];
                int on = nums[idx];
                if(on % 2 == 0){
                    evenSum -= on;
                }
                nums[idx] += val;
                int nn = nums[idx];
                if(nn % 2 == 0){
                    evenSum += nn;
                }
                ans.push_back(evenSum);
            }
            return ans;
        }
    };