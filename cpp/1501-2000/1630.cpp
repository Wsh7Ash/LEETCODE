class Solution {
    public:
        vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
            vector<bool> res;
            for(int i = 0; i < l.size(); i++){
                int left = l[i], right = r[i];
                vector<int> sub(nums.begin() + left, nums.begin() + right + 1);
                sort(sub.begin(), sub.end());
                bool valid = true;
                int diff = sub[1] - sub[0];
                for(int j = 2; j < sub.size() && valid; j++){
                    if(sub[j] - sub[j - 1] != diff){
                        valid = false;
                    }
                }
                res.push_back(valid);
            }
            return res;
        }
    };