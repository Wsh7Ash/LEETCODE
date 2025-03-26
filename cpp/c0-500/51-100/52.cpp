class Solution {
public:
    void backtrack(int n, int row, int cols, int diag, int antiDiag, int& count){
        if(row == n){
            count++;
            return;
        }
        for(int c = 0; c < n; c++){
            int diag1 = row - c + n - 1;
            int antiDiag1 = row + c;

            if((cols & (1 << c)) || (diag & (1 << diag1)) || (antiDiag & (1 << antiDiag1))){
                continue;
            }

            cols |= (1 << c);
            diag |= (1 << diag1);
            antiDiag |= (1 << antiDiag1);

            backtrack(n, row + 1, cols, diag, antiDiag, count);

            cols &= ~(1 << c);
            diag &= ~(1 << diag1);
            antiDiag &= ~(1 << antiDiag1);
        }
    }
    
    int totalNQueens(int n) {
       int count = 0;

       backtrack(n, 0, 0, 0, 0, count);
       return count;
    }
};