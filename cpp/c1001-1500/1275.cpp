class Solution {
    public:
        string tictactoe(vector<vector<int>>& moves) {
            vector<int> rows(3, 0);
            vector<int> cols(3, 0);
            int diagonal = 0;
            int antiDiagonal = 0;
    
            for(int i = 0; i < moves.size(); i++){
                int row = moves[i][0];
                int col = moves[i][1];
                int player = (i % 2 == 0) ? 1 : -1;
    
                rows[row] += player;
                cols[col] += player;
    
                if(row == col) diagonal += player;
                if(row + col == 2) antiDiagonal += player;
    
                if(abs(rows[row]) == 3 || abs(cols[col]) == 3 || 
                   abs(diagonal) == 3 || abs(antiDiagonal) == 3)
                  { return (player == 1) ? "A" : "B";
    }        }
        return (moves.size() == 9) ? "Draw" : "Pending";
        }
    
    };