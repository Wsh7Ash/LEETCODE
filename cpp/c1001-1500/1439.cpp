class Solution {
    public:
        int kthSmallest(vector<vector<int>>& mat, int k) {
            vector<int> row = mat[0];
    
            for(int i = 1; i <mat.size(); i++)
            {
                vector<int> nextRow;
                for(int sum : row){
                    for(int num : mat[i]){
                        nextRow.push_back(sum + num);
                    }
                }
    
                sort(nextRow.begin(), nextRow.end());
                if(nextRow.size() > k){
                    nextRow.resize(k);
                }
                row = nextRow;
            }    
            return row[k - 1];
        }
    };