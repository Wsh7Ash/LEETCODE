class Solution {
    public:
        bool checkPartitioning(string s) {
            int n = s.length();
            vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
            for(int i = 0; i < n; i++){
                isPalindrome[i][i] = true;
            }
            for(int i = 0; i < n - 1; i++){
                if(s[i] == s[i+1]){
                    isPalindrome[i][i + 1] = true;
                }
            }
    
            for(int l = 3; l <= n; l++){
                for(int i = 0; i <= n - l; i++){
                    int j = i + l - 1;
                    if(s[i] == s[j] && isPalindrome[i + 1][j - 1]){
                        isPalindrome[i][j] = true;
                    }
                }
            }
    
            for(int i = 0; i < n - 2; i++){
                for(int j = i + 1; j < n - 1; j++){
                    if(isPalindrome[0][i] && isPalindrome[i+1][j] && isPalindrome[j+1][n - 1]){
                        return true;
                    }
                }
            }
            return false;
        }
    };