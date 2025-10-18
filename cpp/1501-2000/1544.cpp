class Solution {
    public:
        string makeGood(string s) {
            stack<char> st;
            
            for(char c : s){
                if(!st.empty() && isBadPair(st.top(), c)){
                    st.pop();
                }else{
                    st.push(c);
                }
            }
    
            string res = "";
            while(!st.empty()){
                res = st.top() + res;
                st.pop();
            }
            return res;
        }
    
    private:
        bool isBadPair(char a, char b){
            return (tolower(a) == tolower(b) && a != b);
        }
    };