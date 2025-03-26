class Solution {
    public:
        vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
            if(mat.empty() || mat[0].empty()) return {};
    
            int m = mat.size();
            int n = mat[0].size();
            vector<int> res;
            int row = 0, col = 0;
            bool goingUp = true;
    
            while(res.size() < m * n){
                if(goingUp){
                    while(row >= 0 && col < n){
                        res.push_back(mat[row][col]);
                        row--;
                        col++;
                    }
                    row++;
                    if(col == n){
                        row++;
                        col--;
                    }
                    goingUp = false;
                    
                }else{
                    while(row < m && col >= 0){
                        res.push_back(mat[row][col]);
                        row++;
                        col--;
                    }
                    col++;
                    if(row == m){
                        row--;
                        col++;
                    }
                    goingUp = true;
                }
            } 
            return res;
        }
    };