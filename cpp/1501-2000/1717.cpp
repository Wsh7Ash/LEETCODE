class Solution {
    public:
        int maximumGain(string s, int x, int y) {
            int o1 = calculateGain(s, 'a', 'b', x, 'b', 'a', y);
            int o2 = calculateGain(s, 'b', 'a', y, 'a', 'b', x);
            
            return max(o1, o2);
        }
        
        int calculateGain(string s, char firstChar1, char firstChar2, int firstPoints, 
                         char secondChar1, char secondChar2, int secondPoints) {
            int totalPoints = 0;
            stack<char> st;
            
            for(char c : s) {
                if(!st.empty() && st.top() == firstChar1 && c == firstChar2) {
                    st.pop();
                    totalPoints += firstPoints;
                } else {
                    st.push(c);
                }
            }
            
            string remaining = "";
            while(!st.empty()) {
                remaining += st.top();
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());
            
            for(char c : remaining) {
                if(!st.empty() && st.top() == secondChar1 && c == secondChar2) {
                    st.pop();
                    totalPoints += secondPoints;
                } else {
                    st.push(c);
                }
            }
            
            return totalPoints;
        }
    };