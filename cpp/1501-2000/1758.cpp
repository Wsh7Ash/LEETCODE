class Solution {
    public:
        int minOperations(string s) {
            int n = s.length();
            int countWith0 = 0;
            int countWith1 = 0;
    
            for(int i = 0; i < n; i++){
                if(i % 2 == 0){
                    if(s[i] != '0'){
                        countWith0++;
                    }else{
                        countWith1++;
                    }
                }else{
                    if(s[i] != '1'){
                        countWith0++;
                    }else{
                        countWith1++;
                    }
                }
            }
            return min(countWith0, countWith1);
        }
    };