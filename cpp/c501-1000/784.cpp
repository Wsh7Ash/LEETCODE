class Solution {
    public:
        vector<string> letterCasePermutation(string s) {
            vector<string> res;
            backtrack(s, 0, res);
            return res;
        }
        void backtrack(string& s, int i, vector<string>& res){
            if(i == s.size()){
                res.push_back(s);
                return;
            }
            if(isalpha(s[i])){
                s[i] = tolower(s[i]);
                backtrack(s, i+1, res);
                s[i] = toupper(s[i]);
                backtrack(s, i+1, res);
            }else{
                backtrack(s, i+1, res);
            }
        }
    };