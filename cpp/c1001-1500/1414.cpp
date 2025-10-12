class Solution {
    public:
        int findMinFibonacciNumbers(int k) {
            vector<int> fib = {1, 1};
    
            while(fib.back() < k){
                int nextFib = fib[fib.size() - 1] + fib[fib.size() - 2];
                fib.push_back(nextFib);
            }
    
            int count = 0;
            int rem = k;
    
            for(int i = fib.size() - 1; i>= 0 && rem > 0; i--){
                if(fib[i] <= rem){
                    rem -= fib[i];
                    count++;
                }
            }
    
            return count;
        }
    };