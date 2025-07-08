class Solution {
    public:
        int scoreOfParentheses(string s) {
            stack<int> st;
            st.push(0);
            for(char c : s){
                if(c == '('){
                    st.push(0);
                }else{
                    int top = st.top();
                    st.pop();
                    int val = 0;
                    if(top == 0){
                        val = 1;
                    }else{
                        val = 2 * top;
                    }
                    st.top() += val;
                }
            }
            return st.top();
        }
    };