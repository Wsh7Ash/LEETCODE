class Solution {
    public:
        int surfaceArea(vector<vector<int>>& grid) {
           int n = grid.size();
           int total = 0;
    
           for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    total += 4 * grid[i][j] + 2;
                    if(i > 0){
                        total -= 2 * min(grid[i][j], grid[i-1][j]);
                    }
                    if(j > 0){
                        total -= 2 * min(grid[i][j], grid[i][j-1]);
                    }
                }
            }
           } 
           return total;
        }
    };