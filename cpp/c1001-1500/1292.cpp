class Solution {
    public:
        int maxSideLength(vector<vector<int>>& mat, int threshold) {
            int m = mat.size();
            int n = mat[0].size();
    
            vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
    
            for(int i = 1; i <= m; i++){
                for(int j = 1; j <= n; j++){
                    prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
                }
            }
    
            int left = 0, right = min(m, n);
            int res = 0;
    
            while(left <= right){
                int mid = left + (right - left) / 2;
                bool found = false;
    
                for(int i = mid; i <= m; i++){
                    for(int j = mid; j <= n; j++){
                        int sum = prefix[i][j] - prefix[i - mid][j] - prefix[i][j-mid] + prefix[i-mid][j-mid];
                        if(sum <= threshold){
                            found = true;
                            break;
                        }
                    }
                    if(found) break;
                }
    
                if(found){
                    res = mid;
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            return res;
    
        }
    };