class Solution {
    public:
        vector<int> luckyNumbers(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
    
            vector<int> res;
            vector<int> colMax(n, 0);
    
            for(int j = 0; j < n; j++){
                int maxVal = matrix[0][j];
                for(int i = 1; i < m; i++){
                    maxVal = max(maxVal, matrix[i][j]);
                }
                colMax[j] = maxVal;
            }
    
            for(int i = 0; i < m; i++){
                int minVal = matrix[i][0];
                int minCol = 0;
                for(int j = 1; j < n; j++){
                    if(matrix[i][j] < minVal){
                        minVal = matrix[i][j];
                        minCol = j;
                    }
                }
    
                if(minVal == colMax[minCol]){
                    res.push_back(minVal);
                }
            }
    
            return res;
        }
    };