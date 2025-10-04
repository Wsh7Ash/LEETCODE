class Solution {
    public:
        vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
            int m =  mat.size();
            int n = mat[0].size();
    
            vector<vector<int>> prefixSum(m+1, vector<int>(n+1, 0));
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    prefixSum[i+1][j+1] = mat[i][j] + prefixSum[i][j+1] + prefixSum[i+1][j] - prefixSum[i][j];
                }
            }
    
            vector<vector<int>> res(m, vector<int>(n, 0));
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    int r1 = max(0, i - k);
                    int c1 = max(0, j - k);
                    int r2 = min(m - 1, i + k);
                    int c2 = min(n - 1, j + k);
    
                    res[i][j] = prefixSum[r2 + 1][c2 + 1] - prefixSum[r1][c2 + 1] - prefixSum[r2+1][c1] + prefixSum[r1][c1];
    
                }
            }
    
            return res;
        }
    };