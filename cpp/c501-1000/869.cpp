class Solution {
    public:
        bool reorderedPowerOf2(int n) {
           string s = to_string(n);
           sort(s.begin(), s.end());
           for(int i = 0; i < 30; i++){
            int power = 1 << i;
            string powerStr = to_string(power);
            if(powerStr.size() == s.size()){
                sort(powerStr.begin(), powerStr.end());
                if(powerStr == s){
                    return true;
                }
            }else if(powerStr.size() > s.size()) break;
           } 
           return false;
        }
    };