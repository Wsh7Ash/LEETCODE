class Solution {
    public:
        vector<string> simplifiedFractions(int n) {
            vector<string> res;
    
            for(int d = 2; d <= n; d++){
                for(int nu = 1; nu < d; nu ++){
                    if(gcd(nu, d) == 1){
                        res.push_back(to_string(nu) + "/" + to_string(d));
                    }
                }
            }
    
            return res;    
        }
    
    private:
        int gcd(int a, int b){
            while(b != 0){
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
    };