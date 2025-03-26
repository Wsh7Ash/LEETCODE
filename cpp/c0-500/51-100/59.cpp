class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

      vector<vector<int>> matrix(n, vector<int>(n, 0));

      int num = 1;
      int total = n * n;
      int top = 0, bottom = n - 1;  
      int left = 0, right = n - 1;

      while(num <= total){
        for(int j = left; j <= right && num <= total; j++){
            matrix[top][j] = num++;
        }
        top++;

        for(int i = top; i <= bottom && num <= total; i++){
            matrix[i][right] = num++;
        }
        right--;
        
        for(int j = right; j >= left && num <= total; j--){
            matrix[bottom][j] = num++;
        }
        bottom--;

        for(int i = bottom; i >= top && num <= total; i--){
            matrix[i][left] = num++;
        }
        left++;
      }  
      return matrix;
    }
};