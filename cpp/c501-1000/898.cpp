class Solution {
    public:
        int subarrayBitwiseORs(vector<int>& arr) {
            unordered_set<int> res;
            unordered_set<int> cur;
            unordered_set<int> next;
    
            for(int num : arr){
                next.clear();
                next.insert(num);
                for(int val : cur){
                    next.insert(val | num);
                }
                cur = next;
                res.insert(cur.begin(), cur.end());
            }
            return res.size();
        }
    };