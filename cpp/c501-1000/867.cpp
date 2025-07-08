class Solution {
    public:
        vector<vector<int>> transpose(vector<vector<int>>& matrix) {
            int m = matrix.size();
            if(m == 0) return {};
            int n = matrix[0].size();
            vector<vector<int>> tr(n, vector<int>(m));
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    tr[j][i] = matrix[i][j];
                }
            }
            return tr;
        }
    };