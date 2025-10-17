class Solution {
    public:
        int numSubmat(vector<vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();
            int res = 0;
    
            vector<vector<int>> left(m, vector<int>(n, 0));
    
            for(int i = 0; i < m; i++){
                int count = 0;
                for(int j = 0; j < n; j++){
                    if(mat[i][j] == 1){
                        count++;
                    }else{
                        count = 0;
                    }
                    left[i][j] = count;
                }
            }
    
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(mat[i][j] == 0)continue;
                    int minWidth = left[i][j];
                    for(int k = i; k >= 0 && mat[k][j] == 1; k--){
                        minWidth = min(minWidth, left[k][j]);
                        res += minWidth;
                    }
                }
            }
    
            return res;
        }
    };