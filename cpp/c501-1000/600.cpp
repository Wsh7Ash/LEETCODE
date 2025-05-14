class Solution {
    public:
        int findIntegers(int n) {
         string binary;
         while(n > 0){
            binary += (n % 2) + '0';
            n /= 2;
         }   
         reverse(binary.begin(), binary.end());
         int len = binary.length();
    
         vector<vector<int>> dp(len + 1, vector<int>(2, 0));
         dp[1][0] = 1;
         dp[1][1] = 1;
    
         for(int i =2; i <= len; i++){
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
            dp[i][1] = dp[i-1][0];
         }
        int res = 0;
        bool prev_one = false;
        for(int i = 0; i < len; i++){
            int bit = binary[i] - '0';
            int pos = len - i -1;
            if(bit == 1){
                res += dp[pos + 1][0];
                if(prev_one) return res;
                prev_one = true;
            }else{
                prev_one = false;
            }
        }
        bool valid = true;
        for(int i = 1; i < len; i++){
            if(binary[i] == '1' && binary[i-1] =='1'){
                valid = false;
                break;
            }
        }
        if(valid) res++;
    
        return res;
        }
    };