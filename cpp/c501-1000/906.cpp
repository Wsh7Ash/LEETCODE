class Solution {
    public:
        int superpalindromesInRange(string left, string right) {
            long long l = stoll(left);  
            long long r = stoll(right);
            int count = 0;
            
            long long mr = (long long)sqrt(r) + 1;
    
            for(long long k = 1; k < 100000; k++){
                string s = to_string(k);
                string rev_s = s;
                reverse(rev_s.begin(), rev_s.end());
                
                string op = s + rev_s.substr(1);
                long long on = stoll(op);
                
                if(on > mr) break;
                
                long long os = on * on;
                if(os >= l && os <= r && isPalindrome(os)) count++;
    
                string ep = s + rev_s;
                long long en = stoll(ep);
                
                if(en <= mr) {
                    long long es = en * en;
                    if(es >= l && es <= r && isPalindrome(es)) count++;
                }
            }  
            return count;
        }
        
        bool isPalindrome(long long num){
            string s = to_string(num);
            string rev_s = s;
            reverse(rev_s.begin(), rev_s.end());
            return s == rev_s;
        }
    };