class Solution {
    public:
        bool validTicTacToe(vector<string>& board) {
            int xc = 0, oc = 0;
            for(const string& row : board){
                for(char c : row){
                    if(c == 'X') xc++;
                    else if(c == 'O') oc++;
                }
            }
            if(oc != xc && oc != xc - 1) return false;
    
            bool xw = checkWin(board, 'X');
            bool ow = checkWin(board, 'O');
    
            if(xw && ow) return false;
            if(xw) return xc == oc + 1;
            if(ow) return oc == xc;
            return true;
        }
    
        bool checkWin(const vector<string>& board, char player){
            for(int i = 0; i < 3; i++){
                if(board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
                if(board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
            }
            if(board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
            if(board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
            return false;
        }
    };