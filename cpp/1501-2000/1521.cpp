class Solution {
    public:
        int closestToTarget(vector<int>& arr, int target) {
            int n = arr.size();
            int minDiff = INT_MAX;
            unordered_set<int> cur, next;
            for(int i = 0; i < n; i++){
                next.clear();
                next.insert(arr[i]);
                for(int val : cur){
                    next.insert(val & arr[i]);
                }
                for(int val : next){
                    minDiff = min(minDiff, abs(val - target));
                }
                cur = next;
            }
            return minDiff;
        }
    };