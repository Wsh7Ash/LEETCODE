class Solution {
    public:
        int primePalindrome(int n) {
            if(n <= 2) return 2;
            if(n <= 3) return 3;
            if(n <= 5) return 5;
            if(n <= 7) return 7;
            if(n >= 8 && n <= 11) return 11;
            for(int i = 1; i < 100000; i++){
                string s = to_string(i);
                string rev(s.rbegin(), s.rend());
                int can = stoi(s + rev.substr(1));
                if(can >= n && isPrime(can)) return can;
                can = stoi(s + rev);
                if(can >= n && isPrime(can)) return can;
            }
            return -1;
        }
    
        bool isPrime(int num){
            if(num < 2) return false;
            if(num == 2) return true;
            if(num % 2 == 0) return false;
            for(int i = 3; i * i <= num; i += 2){
                if(num % i == 0){
                    return false;
                }
            }
            return true;
        }
    };