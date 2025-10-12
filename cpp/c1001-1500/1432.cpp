class Solution {
    public:
        int maxDiff(int num) {
            string s = to_string(num);
    
            string maxNum = s;
            char target = ' ';
            for(char c : s){
                if(c != '9'){
                    target = c;
                    break;
                }
            }
    
            if(target != ' '){
                replace(maxNum.begin(), maxNum.end(), target, '9');
            }
    
            string minNum = s;
            if(s[0] != '1'){
                replace(minNum.begin(), minNum.end(), s[0], '1');
            }else{
                target = ' ';
                for(int i = 1; i < s.size(); i++){
                    if(s[i] != '0' && s[i] != '1'){
                        target = s[i];
                        break;
                    }
                }
    
                if(target != ' '){
                    replace(minNum.begin(), minNum.end(), target, '0');
                }
            }
            return stoi(maxNum) - stoi(minNum);
        }
    };