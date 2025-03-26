class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        stack.push(-1);
        int maxlen = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                stack.push(i);
            }else{
                stack.pop();
                if(stack.empty()){
                    stack.push(i);
                }else{
                    maxlen = max(maxlen, i - stack.top());
                }
            }
        }
        return maxlen;
    }
};