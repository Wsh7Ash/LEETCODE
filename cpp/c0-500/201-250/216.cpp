class Solution {
    private:
        void backtrack(vector<vector<int>>& result, vector<int>& current, 
                      int k, int target, int start) {
            // If we have k numbers and target is reached
            if (current.size() == k && target == 0) {
                result.push_back(current);
                return;
            }
            
            // If we have k numbers but target not reached, or target becomes negative
            if (current.size() >= k || target <= 0) {
                return;
            }
            
            // Try each number from start to 9
            for (int i = start; i <= 9; i++) {
                current.push_back(i);
                backtrack(result, current, k, target - i, i + 1);
                current.pop_back();
            }
        }
        
    public:
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<vector<int>> result;
            vector<int> current;
            
            backtrack(result, current, k, n, 1);
            return result;
        }
    };