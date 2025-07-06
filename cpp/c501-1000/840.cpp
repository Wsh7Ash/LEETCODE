class Solution {
    public:
        int numMagicSquaresInside(vector<vector<int>>& grid) {
            int rows = grid.size();
            if(rows == 0) return 0;
            int cols = grid[0].size();
            if(cols == 0) return 0;
    
            int count = 0;
            for(int i = 0; i <= rows - 3; i++){
                for(int j = 0; j <= cols - 3; j++){
                    if(isMagicSquare(grid, i, j)){
                        count++;
                    }
                }
            }
            return count;
        }
    
        bool isMagicSquare(vector<vector<int>>& grid, int x, int y){
            unordered_set<int> seen;
            int sum = 0;
    
            for(int i = x; i < x + 3; i++){
                for(int j = y; j < y + 3; j++){
                    int num = grid[i][j];
                    if(num < 1 || num > 9 || seen.count(num)){
                        return false;
                    }
                    seen.insert(num);
                }
            }
            sum = grid[x][y] + grid[x][y+1] + grid[x][y+2];
    
            for(int i = x + 1; i < x + 3; i++){
                int rowSum = grid[i][y]+ grid[i][y+1] + grid[i][y+2];
                if(rowSum != sum){
                    return false;
                }
            }
    
            for(int j = y; j < y + 3; j++){
                int colSum = grid[x][j]+ grid[x+1][j] + grid[x+2][j];
                if(colSum != sum){
                    return false;
                }
            }
            
            int diag1 = grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2];
            int diag2 = grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y];
            if(diag1 != sum || diag2 != sum) return false;
    
            return true;
        }
    };