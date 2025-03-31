class Solution {
    public:
        void backtrack(int pos, int n, vector<bool>& used, int& count){
            if(pos > n){
                count++;
                return;
            }
            for(int num = 1; num <= n; num++){
                if(!used[num] && (num % pos == 0 || pos % num == 0)){
                    used[num] = true;
                    backtrack(pos+1, n, used, count);
                    used[num] = false;
                }
            }
        }
        int countArrangement(int n) {
            int count = 0;
            vector<bool> used(n + 1, false);
            backtrack(1, n, used, count);
            return count;
        }
    };