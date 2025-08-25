class Solution {
    public:
        bool parseBoolExpr(string expression) {
            stack<char> st;
            for(char c : expression){
                if(c == ')'){
                    vector<char> args;
                    while(st.top() != '('){
                        args.push_back(st.top());
                        st.pop();
                    }
                    st.pop();
                    char op = st.top();
                    st.pop();
                    if(op == '!'){
                        char res = (args[0] == 't') ? 'f' : 't';
                        st.push(res);
                    }else if(op == '&'){
                        bool allTrue = true;
                        for(char arg : args){
                            if(arg == 'f'){
                                allTrue = false;
                                break;
                            }
                        }
                        st.push(allTrue ? 't' : 'f');
                    }else if(op == '|'){
                        bool anyType = false;
                        for(char arg : args){
                            if(arg == 't'){
                                anyType = true;
                                break;
                            }
                        }
                        st.push(anyType ? 't' : 'f');
                    }
                }else if(c != ',') st.push(c);
            }
            return st.top() == 't';
        }
    };