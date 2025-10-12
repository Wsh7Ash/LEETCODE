class Solution {
    public:
        vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
            vector<vector<int>> groups;
    
            for(int i = 0; i < nums.size(); i++){
                for(int j = 0; j < nums[i].size(); j++){
                    int diagonal = i + j;
                    if(diagonal >= groups.size()){
                        groups.resize(diagonal + 1);
                    }
                    groups[diagonal].push_back(nums[i][j]);
                }
            }
    
            vector<int> res;
            for(auto& group : groups){
                res.insert(res.end(), group.rbegin(), group.rend());
            }
            return res;
        }
    };