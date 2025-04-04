class Solution {
    public:
        int dfs(vector<int>& boxes, int l, int r, int k, vector<vector<vector<int>>>& memo){
            if(l > r) return 0;
    
            if(memo[l][r][k] != 0) return memo[l][r][k];
            int ol = l, ok = k;
            while(l < r && boxes[l] == boxes[l + 1]){
                l++;
                k++;
            }
            int res = (k+1)*(k+1) + dfs(boxes,l+1,r,0,memo);
            
            for(int m = l + 1; m <= r; m++){
                if(boxes[l] == boxes[m]){
                    res = max(res, dfs(boxes, l+1, m-1, 0, memo) + dfs(boxes, m, r, k+1, memo));
                }
            }
            memo[ol][r][ok] = res;
            return res;
        }
    
        int removeBoxes(vector<int>& boxes) {
            int n = boxes.size();
            vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, 0)));
            // memset(memo, 0, sizeof(memo));
            return dfs(boxes, 0, n-1, 0, memo);
        }
    };