class Solution {
    public:
        void  backtrack(vector<int>& nums, int index, vector<int>& cur, set<vector<int>>& result){
            if(cur.size() >= 2){
                result.insert(cur);
            }
    
            for(int i = index; i < nums.size(); i++){
                if(!cur.empty() && nums[i] < cur.back()){
                    continue;
                }
                cur.push_back(nums[i]);
                backtrack(nums, i+1, cur, result);
                cur.pop_back();
            }
        }
        
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            vector<int> cur;
            set<vector<int>> result;
    
            backtrack(nums, 0, cur, result);
            return vector<vector<int>>(result.begin(), result.end());
    
        }
    };