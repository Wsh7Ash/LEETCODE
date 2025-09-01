class Solution {
    public:
        int largest1BorderedSquare(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> right(m , vector<int>(n, 0));
            vector<vector<int>> down(m , vector<int>(n, 0));
    
            for(int i = m - 1; i >= 0; i--){
                for(int j = n - 1; j >= 0; j--){
                    if(grid[i][j] == 1){
                        right[i][j] = (j == n- 1) ? 1 : right[i][j+1] + 1;
                        down[i][j] = (i == m -1) ? 1 : down[i+1][j] + 1;
                    }else{
                        right[i][j] = 0;
                        down[i][j] = 0;
                    }
                }
            }
            int maxSide = 0;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    int side = min(right[i][j], down[i][j]);
                    while(side > maxSide){
                        if(right[i+side-1][j] >= side && down[i][j+side-1] >= side){
                            maxSide = side;
                            break;
                        }
                        side--;
                    }
                }
            }
            return maxSide * maxSide;
        }
    };