class Solution {
    public:
        int kthLargestValue(vector<vector<int>>& matrix, int k) {
            int m = matrix.size();
            int n = matrix[0].size();
            vector<vector<int>> xor_values(m, vector<int>(n, 0));
            xor_values[0][0] = matrix[0][0];
            for(int i = 1; i < m; i++){
                xor_values[i][0] = xor_values[i-1][0] ^ matrix[i][0];
            }
            for(int j = 1; j < n; j++){
                xor_values[0][j] = xor_values[0][j-1] ^ matrix[0][j];
            }
            for(int i = 1; i < m; i++){
                for(int j = 1; j < n; j++){
                    xor_values[i][j] = matrix[i][j] ^ xor_values[i-1][j] ^ xor_values[i][j-1] ^ xor_values[i-1][j-1];
                }
            }
            vector<int> values;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    values.push_back(xor_values[i][j]);
                }
            }
            sort(values.begin(), values.end(), greater<int>());
            return values[k-1];
        }
    };