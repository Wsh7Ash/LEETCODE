class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& grid) {
            
            int n = grid.size();
            if(n == 1) return grid[0][0];
    
            int pm1 = INT_MAX, pm2 = INT_MAX, pmp = -1;
    
            for(int j = 0; j < n; j++){
                if(grid[0][j] < pm1){
                    pm2 = pm1;
                    pm1 = grid[0][j];
                    pmp = j;
                }else if(grid[0][j] < pm2){
                    pm2 = grid[0][j];
                }
            }
    
            for(int i = 1; i < n; i++){
                int cm1 = INT_MAX, cm2 = INT_MAX, cmp = -1;
    
                for(int j = 0; j < n; j++){
                    int pathSum = grid[i][j]  + (j == pmp ? pm2 : pm1);
    
                    if(pathSum < cm1){
                        cm2 = cm1;
                        cm1 = pathSum;
                        cmp = j;
                    }else if(pathSum < cm2){
                        cm2 = pathSum;
                    }
                }
    
                pm1 = cm1;
                pm2 = cm2;
                pmp = cmp;
            }
    
            return pm1;
        }
    };