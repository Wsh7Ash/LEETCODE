class Solution {
    public:
        string customSortString(string order, string s) {
            vector<int> count(26,0);
            for(char c : s){
                count[c - 'a']++;
            }
            string res;
            for(char c : order){
                while(count[c - 'a'] > 0){
                    res += c;
                    count[c - 'a']--;
                }
            }
            for(int i = 0; i < 26; i++){
                while(count[i] > 0){
                    res += (char)(i + 'a');
                    count[i]--;
                }
            }
            return res;
        }
    };