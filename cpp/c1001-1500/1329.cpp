class Solution {
    public:
        vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();
    
            for(int i = 1; i < m; i++){
                sortDiagonal(mat, i, 0, m, n);
            }
    
            for(int j = 0; j < n; j++){
                sortDiagonal(mat, 0, j, m, n);
            }
            return mat;
        }
    
    private:
        void sortDiagonal(vector<vector<int>>& mat, int startRow, int startCol, int m, int n){
    
            vector<int> diagonal;
            int r = startRow, c = startCol;
    
            while(r < m && c < n){
                diagonal.push_back(mat[r][c]);
                r++;
                c++;
            }
    
            sort(diagonal.begin(), diagonal.end());
    
            r = startRow;
            c = startCol;
            int index = 0;
    
            while(r < m && c < n){
                mat[r][c] = diagonal[index++];
                r++;
                c++;
            }
        }
    };