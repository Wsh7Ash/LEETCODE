class Solution {
    public:
        int countCharacters(vector<string>& words, string chars) {
            array<int, 26> charCounts = {0};
    
            for(char  c : chars){
                charCounts[c - 'a']++;
            }
    
            int res = 0;
    
            for(const string& word : words){
                array<int,26> tempCounts = charCounts;
                bool canForm = true;
    
                for(char c : word){
                    if(tempCounts[c - 'a'] == 0){
                        canForm = false;
                        break;
                    }
                    tempCounts[c - 'a']--;
                }
                if(canForm){
                    res += word.length();
                }
            }
            return res;
        }
    };