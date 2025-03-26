class Solution {
    public:
        string smallestGoodBase(string n) {
            long long num = stoll(n);
    
            int maxk = log2(num + 1);
    
            for(int k = maxk; k >= 2; k--){
                long long left = 2;
                long long right = pow(num, 1.0/(k-1)) + 1;
    
                while(left < right){
                    long long mid = left + (right - left) / 2;
                    long long sum = 0;
                    unsigned long long cur = 1;
    
                    for(int i = 0; i < k; i++){
                        sum += cur;
                        if(sum >= num) break;
                        cur *= mid;
                    }
                    if(sum == num) return to_string(mid);
                    else if(sum < num) left = mid + 1;
                    else right = mid;
                }
            }
            return to_string(num - 1);
        }
    
    };