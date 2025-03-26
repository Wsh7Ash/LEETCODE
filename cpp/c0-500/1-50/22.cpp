class Solution {
public:
    void track(vector<string>& result, string current, int open, int close, int max){
        if(current.length() == max * 2){
            result.push_back(current);
            return;
        }
        if(open < max){
            track(result, current + '(', open + 1, close, max);
        }
        if(close < open){
            track(result, current + ')', open, close + 1, max);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        track(result, "", 0,0, n);
        return result;
    }
};