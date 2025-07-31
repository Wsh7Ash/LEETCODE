class Solution {
    public:
        int numRookCaptures(vector<vector<char>>& board) {
            int rookRow = -1, rookCol = -1;
    
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if(board[i][j] == 'R'){
                        rookRow = i;
                        rookCol = j;
                        break;
                    }
                }
                if(rookRow != -1) break;
            }
            int caps = 0;
    
            for(int j = rookCol - 1; j >= 0; j--){
                if(board[rookRow][j] == 'p'){
                    caps++;
                    break;
                }else if(board[rookRow][j] != '.') break;
            }
    
            for(int j = rookCol + 1; j < 8; j++){
                if(board[rookRow][j] == 'p'){
                    caps++;
                    break;
                }else if(board[rookRow][j] != '.') break;
            }
            
            for(int i = rookRow - 1; i >= 0; i--){
                if(board[i][rookCol] == 'p'){
                    caps++;
                    break;
                }else if(board[i][rookCol] != '.') break;
            }
    
            for(int i = rookRow + 1; i < 8; i++){
                if(board[i][rookCol] == 'p'){
                    caps++;
                    break;
                }else if(board[i][rookCol] != '.') break;
            }
            return caps;
        }
    };