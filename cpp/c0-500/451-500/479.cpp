class Solution {
    public:
        int largestPalindrome(int n) {
            if(n == 1) return 9;
    
            long upper = pow(10, n) - 1;
            long lower = pow(10, n - 1);
    
            for(long i = upper; i >= lower; i--){
                string s = to_string(i);
                string t = s;
                reverse(t.begin(), t.end());
                long palindrome = stol(s+t);
    
                for(long j = upper; j * j >= palindrome; j--){
                    if(palindrome % j == 0 && palindrome / j >= lower){
                        return palindrome % 1337;
                    }
                }
            }
            return -1;
        }
    };