class Solution {
    public:
        bool isValid(string s) {
            vector<char> st;
            for(char c : s){
                st.push_back(c);
                if(st.size() >= 3){
                    int n = st.size();
                    if(st[n-3] == 'a' && st[n-2] == 'b' && st[n-1] == 'c'){
                        st.pop_back();
                        st.pop_back();
                        st.pop_back();
                    }
                }
    
            }
            return st.empty();
        }
    };