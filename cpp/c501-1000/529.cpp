class Solution {
    public:
        int countMines(vector<vector<char>>& board, int x, int y, int m, int n){
            int count = 0;
            int dirs[8][2] = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1},{1,-1}, {1,0}, {1,1}};
            for(auto dir : dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'M'){
                    count++;
                }
            }
            return count;
        }
    
        vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
            int m = board.size();
            if(m == 0) return board;
            int n = board[0].size();
            int x = click[0], y = click[1];
    
            if(board[x][y] == 'M'){
                board[x][y] = 'X';
                return board;
            }
            int count = countMines(board, x, y, m, n);
            if(count > 0){
                board[x][y] = '0' + count;
                return board;
            }
            queue<pair<int, int>> q;
            q.push({x, y});
            board[x][y] = 'B';
            
            int dirs[8][2] = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1},{1,-1}, {1,0}, {1,1}};
            
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                int i = cur.first;
                int j = cur.second;
    
                for(auto dir : dirs){
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if(ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'E'){
                        int cnt = countMines(board, ni, nj, m, n);
                        if(cnt == 0){
                            board[ni][nj] = 'B';
                            q.push({ni, nj});
                        }else{
                            board[ni][nj] = '0' + cnt;
                        }
                    }
                }
            }
            return board;
        }
    };