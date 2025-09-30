class Solution {
    public:
        vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
            int n = colsum.size();
    
            int twos = 0, ones = 0, zeros = 0;
            for(int sum : colsum){
                if(sum == 2) twos++;
                else if(sum == 1) ones++;
                else zeros++;
            }
    
            if(upper + lower != twos * 2 + ones ||
                upper < twos || 
                lower < twos || 
                upper > twos + ones || 
                lower > twos + ones) return {};
    
            vector<vector<int>> res(2, vector<int>(n, 0));
            int upperOnes = upper - twos;
            int lowerOnes = lower - twos;
    
            for(int i = 0; i < n; i++){
                if(colsum[i] == 2){
                    res[0][i] = res[1][i] = 1;
                }
                else if(colsum[i] == 1){
                    if(upperOnes > 0){
                        res[0][i] = 1;
                        upperOnes--;
                    }else{
                        res[1][i] = 1;
                        lowerOnes--;
                    }
                }
            }
            return res;
        }
    };