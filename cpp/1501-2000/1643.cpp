class Solution {
    public:
        string kthSmallestPath(vector<int>& destination, int k) {
            int v = destination[0];
            int h = destination[1];
            vector<vector<int>> comb(h + v + 1, vector<int>(h + v + 1, 0));
            for(int i = 0; i <= h + v; i++){
                comb[i][0] = comb[i][i] = 1;
                for(int j = 1; j < i; j++){
                    comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
                }
            }
            string res;
            int remV = v;
            int remH = h;
            for(int i = 0; i < h + v; i++){
                if(remH == 0){
                    res += 'V';
                    remV--;
                    continue;
                }
                if(remV == 0){
                    res += 'H';
                    remH--;
                    continue;
                }
                int countH = comb[remH + remV - 1][remH - 1];
                if(k <= countH){
                    res += 'H';
                    remH--;
                }else{
                    res += 'V';
                    k -= countH;
                    remV--;
                }
            }
            return res;
        }
    };