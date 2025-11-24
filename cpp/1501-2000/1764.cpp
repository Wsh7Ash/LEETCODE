class Solution {
    public:
        bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
            int n = groups.size();
            int m = nums.size();
            int pos = 0;
    
            for(int i = 0; i < n; i++){
                pos = findSubarray(groups[i], nums, pos);
                if(pos == -1){
                    return false;
                }
                pos += groups[i].size();
            }
            return true;
        }
    
        int findSubarray(vector<int>& target, vector<int>& nums, int startPos){
            int n = nums.size();
            int m = target.size();
            for(int i = startPos; i <= n - m; i++){
                bool match = true;
                for(int j = 0; j < m; j++){
                    if(nums[i + j] != target[j]){
                        match = false;
                        break;
                    }
                }
                if(match){
                    return i;
                }
            }
            return -1;
        }
    };