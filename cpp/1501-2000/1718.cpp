class Solution {
    public:
        vector<int> constructDistancedSequence(int n) {
            int size = 2 * n - 1;
            vector<int> res(size, 0);
            vector<bool> used(n + 1, false);
            backtrack(res, used, 0, n);
            return res;
        }
    
        bool backtrack(vector<int>& res, vector<bool>& used, int index, int n){
            if(index == res.size()) return true;
            if(res[index] != 0) return backtrack(res, used, index + 1, n);
            for(int num = n; num >= 1; num--){
                if(used[num]) continue;
                if(num == 1){
                    res[index] = 1;
                    used[1] = true;
                    if(backtrack(res, used, index + 1, n)) return true;
                    res[index] = 0;
                    used[1] = false;
                }else{
                    int secPos = index + num;
                    if(secPos < res.size() && res[secPos] == 0){
                        res[index] = num;
                        res[secPos] = num;
                        used[num] = true;
                        if(backtrack(res, used, index + 1, n)) return true;
                        res[index] = 0;
                        res[secPos] = 0;
                        used[num] = false;
                    }
                }
            }
            return false;
        }
    };