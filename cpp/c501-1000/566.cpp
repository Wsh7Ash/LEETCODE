class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
            int m = mat.size();
            int n = mat[0].size();
    
            if(m * n != r * c){
                return mat;
            }
    
            vector<vector<int>> reshaped(r, vector<int>(c));
            vector<int> flattened;
    
            for(auto& row : mat){
                for(int num : row){
                    flattened.push_back(num);
                }
            }
            int index = 0;
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    reshaped[i][j] = flattened[index++];
                }
            }
            return reshaped;
        }
    };