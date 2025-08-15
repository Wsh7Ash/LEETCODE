class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();

        vector<vector<int>> prefix(m , vector<int>(n + 1, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                prefix[i][j + 1] = prefix[i][j] + matrix[i][j]; 
            }
        }

        int  res = 0;

        for(int l = 0; l < n; ++l){
            for(int r = l; r < n; ++r){
                unordered_map<int, int> count;
                count[0] = 1;
                int cur_sum = 0;

                for(int i = 0; i < m; ++i){
                    cur_sum += prefix[i][r+1] - prefix[i][l];
                    if(count.find(cur_sum - target) != count.end()){
                        res += count[cur_sum - target];
                    } 
                    count[cur_sum]++;
                }
            }
        }
        return res;
    }
};