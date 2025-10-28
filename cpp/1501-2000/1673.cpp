class Solution {
    public:
        vector<int> mostCompetitive(vector<int>& nums, int k) {
            vector<int> res;
            int n = nums.size();
            for(int i = 0; i < n; i++){
                int rem = n - i;
                while(!res.empty() && nums[i] < res.back() && res.size() + rem > k){
                    res.pop_back();
                }
                if(res.size() < k){
                    res.push_back(nums[i]);
                }
            }
            return res;
        }
    };