class Solution {
    public:
        int atMostNGivenDigitSet(vector<string>& digits, int n) {
           string s = to_string(n);
           int k = s.size();
           vector<int> digitSet;
           for(const string& d : digits){
            digitSet.push_back(stoi(d));
           } 
           int res = 0;
    
           for(int  i = 1; i < k; i++){
            res += pow(digitSet.size(), i);
           }
    
    
           for(int i = 0; i < k ;i++){
            bool hasSameDigit = false;
            for(int d : digitSet){
                if(d < (s[i] - '0')){
                    res += pow(digitSet.size(), k - i - 1);
                }else if(d == (s[i] - '0')){
                    hasSameDigit = true;
                    break;
                }
                else{
                    break;
                }
            }
            if(!hasSameDigit) return res;
           }
           return res + 1;
        }
    };