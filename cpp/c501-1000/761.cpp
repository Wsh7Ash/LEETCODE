class Solution {
    public:
        string makeLargestSpecial(string s) {
           vector<string> specials;
           int count = 0;
           int start = 0;
           for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                count++;
            }else{
                count--;
            }
            if(count == 0){
                string sub = s.substr(start + 1, i - start - 1);
                specials.push_back('1' + makeLargestSpecial(sub) + '0');
                start = i + 1;
            }
           } 
    
           sort(specials.begin(), specials.end(), greater<string>());
           string res;
           for(const string& special : specials){
            res += special;
           }
           return res;
        }
    };