class Solution {
    public:
        int minDeletionSize(vector<string>& strs) {
            int n = strs.size();
            if(n == 0) return 0;
            int m = strs[0].size();
            int res = 0;
            vector<bool> sorted(n - 1, false);
    
            for(int j = 0 ; j < m; j++){
                bool can_keep = true;
                for(int i = 0; i < n - 1; i++){
                    if(!sorted[i] && strs[i][j] > strs[i+1][j]){
                        can_keep = false;
                        break;
                    }
                }
                if(!can_keep){
                    res++;
                }else{
                    for(int i = 0; i < n - 1; i++){
                        if(strs[i][j] < strs[i+1][j]){
                            sorted[i] = true;
                        }
                    }
                }
            }
            return res;
        }
    };