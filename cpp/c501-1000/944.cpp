class Solution {
    public:
        int minDeletionSize(vector<string>& strs) {
            int deleteCount = 0;
            int rows = strs.size();
            if(rows == 0) return 0;
            int cols = strs[0].size();
    
            for(int col = 0; col < cols; col++){
                for(int row = 1; row < rows; row++){
                    if(strs[row][col] < strs[row-1][col]){
                        deleteCount++;
                        break;
                    }
                }
            }
            return deleteCount;
        }
    };