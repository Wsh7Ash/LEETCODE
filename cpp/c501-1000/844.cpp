class Solution {
    public:
        bool backspaceCompare(string s, string t) {
            return processString(s) == processString(t);
        }
        string processString(const string& str){
            string res;
            for(char c : str){
                if(c != '#'){
                    res.push_back(c);
                }else if(!res.empty()){
                    res.pop_back();
                }
            }
            return res;
        }
    };