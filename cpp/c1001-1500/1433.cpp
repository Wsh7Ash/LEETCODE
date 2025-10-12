class Solution {
    public:
        bool checkIfCanBreak(string s1, string s2) {
            int n = s1.length();
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
    
            bool s1Greater = true;
            bool s2Greater = true;
    
            for(int i = 0; i < n; i++){
                if(s1[i] < s2[i])s1Greater = false;
                if(s2[i] < s1[i])s2Greater = false;
    
                if(!s1Greater && !s2Greater) return false;
            }
    
            return s1Greater || s2Greater;
        }
    };