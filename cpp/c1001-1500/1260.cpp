class Solution {
    public:
        vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
            int m = grid.size();
            int n = grid[0].size();
            int totalElement = m * n;
    
            k = k % totalElement;
    
            if(k == 0) return grid;
    
            vector<vector<int>> res(m, vector<int>(n));
    
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    int curPos = i * n + j;
                    int sourcePos = (curPos - k + totalElement) % totalElement;
    
                    int sourceRow = sourcePos / n;
                    int sourceCol = sourcePos % n;
    
                    res[i][j] = grid[sourceRow][sourceCol];
                }
            }
            return res;
        }
    };