class Solution {
    public:
        string strWithout3a3b(int a, int b) {
            string res;
            while(a > 0 || b > 0){
                int n = res.size();
                bool writeA = false;
                if(n >= 2 && res[n-1] == res[n-2]){
                    if(res[n-1] == 'b'){
                        writeA = true;
                    }
                }else{
                    if(a >= b){
                        writeA = true;
                    }
                }
                if(writeA){
                    if(a == 0){
                        res += 'b';
                        b--;
                    }else{
                    res += 'a';
                    a--;
                    }
                
                }else{
                    if(b == 0){
                        res += 'a';
                        a--;
                    }else{
                        res += 'b';
                        b--;
                    }
                }
            }
            return res;
        }
    };