class Solution {
    public:
        string reformatNumber(string number) {
            string digits = "";
            for(char c : number){
                if(isdigit(c)){
                    digits += c;
                }
            }
    
            vector<string> blocks;
            int i = 0;
            int n = digits.length();
    
            while(n - i > 4){
                blocks.push_back(digits.substr(i, 3));
                i += 3;
            }
    
            int rem = n - i;
            if(rem == 2 || rem == 3){
                blocks.push_back(digits.substr(i));
            }else if(rem == 4){
                blocks.push_back(digits.substr(i, 2));
                blocks.push_back(digits.substr(i + 2, 2));
            }
            string res = blocks[0];
            for(int j = 1; j < blocks.size(); j++){
                res += "-" + blocks[j];
            }
            return res;
        }
    };