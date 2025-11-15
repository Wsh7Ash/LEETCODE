class Solution {
    public:
        int largestSubmatrix(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            vector<vector<int>> heights(m, vector<int>(n, 0));
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(matrix[i][j] == 1){
                        heights[i][j] = (i == 0) ? 1 : heights[i-1][j] + 1;
                    }else{
                        heights[i][j] = 0;
                    }
                }
            }
            
            int maxArea = 0;
            for(int i = 0; i < m; i++){
                vector<int> rowHeights = heights[i];
                sort(rowHeights.begin(), rowHeights.end(), greater<int>());
                for(int j = 0; j < n; j++){
                    int area = rowHeights[j] * (j + 1);
                    maxArea = max(maxArea, area);
                }
            }
            return maxArea;
        }
    };