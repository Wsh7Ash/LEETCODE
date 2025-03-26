vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nidx;
        for(int i =0; i < nums.size(); i++){
            int comp = target - nums[i];
            if(nidx.find(comp) != nidx.end()){
                return {nidx[comp], i};
            }
            nidx[nums[i]] = i;
        }
        return {};
    }