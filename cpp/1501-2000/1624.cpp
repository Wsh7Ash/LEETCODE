class Solution {
    public:
        int maxLengthBetweenEqualCharacters(string s) {
            vector<int> first(26, -1);
            int maxLen = -1;
            for(int i = 0; i < s.length(); i++){
                int idx = s[i] - 'a';
                if(first[idx] == -1){
                    first[idx] = i;
                }else{
                    maxLen = max(maxLen, i - first[idx] - 1);
                }
            }
            return maxLen;
        }
    };