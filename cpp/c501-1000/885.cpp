class Solution {
    public:
        vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
            vector<vector<int>> res;
            int total = rows * cols;
            int step = 1;
            int dir = 0;
            int r = rStart, c = cStart;
            res.push_back({r, c});
    
            while(res.size() < total){
                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < step; j++){
                        switch(dir){
                            case 0: c += 1; break;
                            case 1: r += 1; break;
                            case 2: c -= 1; break;
                            case 3: r -= 1; break;
                        }
    
                        if(r >= 0 && r < rows && c >= 0 && c < cols){
                            res.push_back({r, c});
                            if(res.size() == total){
                                return res;
                            }
                        }
                    }
                    dir = (dir + 1) % 4;
                }
                step += 1;
            }
            return res;
        }
    };