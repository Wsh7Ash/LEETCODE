class Solution {

    private:
        vector<int> findClosestDivisor(int n){
            int bestDiff = INT_MAX;
            vector<int> res(2, 0);
    
            for(int i = 1; i * i <= n; i++){
                if(n % i == 0){
                    int d1 = i;
                    int d2 = n / i;
                    int diff = abs(d1 - d2);
    
                    if(diff < bestDiff){
                        bestDiff = diff;
                        res[0] = d1;
                        res[1] = d2;
                    }
                }
            }
    
            return res;
        }
    
    public:
        vector<int> closestDivisors(int num) {
            vector<int> d1 = findClosestDivisor(num + 1);
            vector<int> d2 = findClosestDivisor(num + 2);
    
            if(abs(d1[0] - d1[1]) <= abs(d2[0] - d2[1])){
                return d1;
            }else{
                return d2;
            }
        }
    };