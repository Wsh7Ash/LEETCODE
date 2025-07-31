class Solution {
    public:
        int numSquarefulPerms(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<int> cur;
            vector<bool> used(nums.size(), false);
            int count = 0;
            backtrack(nums, cur, used, count);
            return count;
        }
    private:
        void backtrack(vector<int>& nums, vector<int>& cur, vector<bool>& used, int& count){
            if(cur.size() == nums.size()){
                count++;
                return;
            }
    
            for(int i = 0; i < nums.size(); i++){
                if(used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])){
                    continue;
                }
    
                if(!cur.empty()){
                    int sum = cur.back() + nums[i];
                    int root = sqrt(sum);
                    if(root * root != sum) continue;
                }
    
                used[i] = true;
                cur.push_back(nums[i]);
                backtrack(nums, cur, used, count);
                cur.pop_back();
                used[i] = false;
            }
        }
    };