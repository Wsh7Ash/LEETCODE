class Solution {
    public:
        string smallestSubsequence(string s) {
            vector<int> last_ocurrence(26, -1);
            vector<int> visited(26, false);
            stack<char> st;
    
            for(int i = 0; i < s.size(); i++){
                last_ocurrence[s[i] - 'a'] = i;
            }
    
            for(int i = 0; i < s.size(); i++){
                char c = s[i];
                if(visited[c - 'a'])continue;
    
                while(!st.empty() && st.top() > c && last_ocurrence[st.top() - 'a'] > i){
                    visited[st.top() - 'a'] = false;
                    st.pop();
                }
                st.push(c);
                visited[c - 'a'] = true;
            }
            string res;
            while(!st.empty()){
                res = st.top() + res;
                st.pop();
            }
            return res;
        }
    };