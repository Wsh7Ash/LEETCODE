class Solution {
    public:
        vector<int> findBall(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<int> res(n, -1);
            for(int col = 0; col < n; col++){
                int curCol = col;
                for(int row = 0; row < m; row++){
                    int dir = grid[row][curCol];
                    int nextCol = curCol + dir;
                    if(nextCol < 0 || nextCol >= n){
                        curCol = -1;
                        break;
                    }
                    if(grid[row][nextCol] != dir){
                        curCol = -1;
                        break;
                    }
                    curCol = nextCol;
                }
                res[col] = curCol;
            }
            return res;
        }
    };