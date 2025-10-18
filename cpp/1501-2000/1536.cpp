class Solution {
    public:
        int minSwaps(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<int> trailingZeros(n, 0);
    
            for(int i = 0; i < n; i++){
                int count = 0;
                for(int j = n - 1; j >= 0; j--){
                    if(grid[i][j] == 0){
                        count++;
                    }else{
                        break;
                    }
                }
                trailingZeros[i] = count;
            }
    
            int swaps = 0;
    
            for(int i = 0; i < n; i++){
                int req = n - i - 1;
    
                int cand = -1;
                for(int j = i; j < n; j++){
                    if(trailingZeros[j] >= req){
                        cand = j;
                        break;
                    }
                }
                if(cand == -1) return -1;
    
                for(int j = cand; j > i; j--){
                    swap(trailingZeros[j], trailingZeros[j - 1]);
                    swaps++;
                }
            }
            return swaps;
        }
    };