class Solution {
    public:
        double champagneTower(int poured, int query_row, int query_glass) {
            vector<vector<double>> tower(query_row + 1, vector<double>(query_row + 1, 0.0));
            tower[0][0] = poured;
    
            for(int i = 0; i < query_row; i++){
                for(int j = 0; j <= i; j++){
                    double exc = tower[i][j] - 1.0;
                    if(exc > 0){
                        tower[i+1][j] += exc / 2.0;
                        tower[i+1][j + 1] += exc / 2.0;
                        tower[i][j] = 1.0;
                    }
                }
            }
            return min(1.0, tower[query_row][query_glass]);
        }
    };