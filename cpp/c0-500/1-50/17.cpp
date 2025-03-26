 void track(const string& digits, string& current, int index, vector<string>& result,const vector<string>& mapping){
        if(index == digits.size()){
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '2'];
        for(char c : letters){
            current.push_back(c);
            track(digits, current, index + 1, result, mapping);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        vector<string> res;
        vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno","pqrs", "tuv", "wxyz"};

        string cur;
        track(digits, cur, 0, res, mapping);
        return res;
    }