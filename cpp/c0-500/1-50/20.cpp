bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapping = {
            { ')','('},
            { ']','['},
            { '}','{'}
        };

        for(char c : s){
            if(mapping.find(c) != mapping.end()){
                char topEle = st.empty() ? '#' : st.top();
                st.pop();

                if(topEle != mapping[c]){
                    return false;
                }
            }else{
                st.push(c);
            }
        }
        return st.empty();
    }