class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int f = 0, t = 0;
            for(int b : bills){
                if(b == 5){
                    f++;
                }else if(b == 10){
                    if(f == 0){
                        return false;
                    }
                    f--;
                    t++;
                }else{
                    if(t > 00 && f > 0){
                        t--;
                        f--;
                    }else if(f >= 3){
                        f -= 3;
                    }else{
                        return false;
                    }
                }
            }
            return true;
        }
    };