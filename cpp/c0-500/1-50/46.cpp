class Solution {
public:
    void track(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result){
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!used[i]){
                used[i] = true;
                current.push_back(nums[i]);

                track(nums, used, current, result);
                current.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        track(nums, used, current, result);
        return result;
    }
};