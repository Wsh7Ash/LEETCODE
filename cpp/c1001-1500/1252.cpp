class Solution {
    public:
        int oddCells(int m, int n, vector<vector<int>>& indices) {
            
            vector<int> rowCount(m, 0);
            vector<int> colCount(n, 0);
    
            for(const auto& index : indices){
                rowCount[index[0]]++;
                colCount[index[1]]++;
            }
    
            int oddRows = 0, oddCols = 0;
            for(int i = 0; i < m; i++) if(rowCount[i] % 2 == 1) oddRows++;
            for(int j = 0; j < n; j++) if(colCount[j] % 2 == 1) oddCols++;
    
            return oddRows * (n - oddCols) + (m - oddRows) * oddCols;
        }
    };