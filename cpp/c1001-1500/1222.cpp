class Solution {
    public:
        vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
            bool board[8][8] = {false};
            for(auto& queen : queens){
                board[queen[0]][queen[1]] = true;
            }
    
            vector<vector<int>> res;
    
            int dirs[8][2] = {{0,1}, {0,-1}, {1, 0}, {-1, 0}, {1,1}, {1, -1}, {-1, 1}, {-1, -1}};
    
            for(auto& dir :  dirs){
                int x = king[0] + dir[0];
                int y = king[1] + dir[1];
                while(x >= 0 && x < 8 && y >= 0 && y < 8){
                    if(board[x][y]){
                        res.push_back({x, y});
                        break;
                    }
                    x+=dir[0];
                    y+=dir[1];
                }
            }
            return res;
        }
    };