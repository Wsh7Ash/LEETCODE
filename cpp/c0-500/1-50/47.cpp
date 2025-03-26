class Solution {
public:
    void track(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result){
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            
            if(!used[i]){
                used[i] = true;
                current.push_back(nums[i]);

                track(nums, used, current, result);
                used[i] = false;
                current.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());
        track(nums, used, current, result);
        return result;
    }
};