class Solution {
    public:
        vector<string> ambiguousCoordinates(string s) {
            vector<string> res;
            string digits = s.substr(1, s.size() - 2);
            int n = digits.size();
            for(int i = 1; i < n; i++){
                string left = digits.substr(0, i);
                string right = digits.substr(i);
                vector<string> leftNums = generateNumbers(left);
                vector<string> rightNums = generateNumbers(right);
                for(const string& ln : leftNums){
                    for(const string& rn : rightNums){
                        res.push_back("(" + ln + ", " + rn + ")");
                    }
                }
            }
            return res;
        }
    
        vector<string> generateNumbers(string s){
            vector<string> res;
            int n = s.size();
            if(n == 1){
                res.push_back(s);
                return res;
            }
            if(s[0] != '0'){
                res.push_back(s);
            }
    
            for(int i = 1; i < n; i++){
                string intPart = s.substr(0, i);
                string fracPart = s.substr(i);
    
                if(intPart.size() > 1 && intPart[0] == '0') continue;
                if(fracPart.back() == '0') continue;
                res.push_back(intPart + "." + fracPart);
            }
            return res;
        }
    };