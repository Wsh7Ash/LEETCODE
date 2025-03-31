class Solution {
    public:
        bool isSUbSequence(string& s, string& t){
            int i = 0, j = 0;
            while(i < s.size() && j < t.size()){
                if(s[i] == t[j]){
                    i++;
                }
                j++;
            }
            return i == s.size();
        }
    
        int findLUSlength(vector<string>& strs) {
            int maxLen = -1;
            for (int i = 0; i < strs.size(); i++){
                bool isValid = true;
                for(int j = 0; j < strs.size(); j++){
                    if(i == j) continue;
                    if(isSUbSequence(strs[i], strs[j])){
                        isValid = false;
                        break;
                    }
                }
                if(isValid){
                    maxLen = max(maxLen, static_cast<int>(strs[i].size()));
                }
            }
            return maxLen;
        }
    };