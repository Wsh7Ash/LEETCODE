class Solution {
    public:
        int numSpecialEquivGroups(vector<string>& words) {
            unordered_set<string> groups;
    
            for(const string& word : words){
                string evenChars;
                string oddChars;
    
                for(int i = 0; i < word.size(); i++){
                    if(i % 2 == 0) evenChars += word[i];
                    else oddChars += word[i];
                }
                sort(evenChars.begin(), evenChars.end());
                sort(oddChars.begin(), oddChars.end());
    
                string key = evenChars + oddChars;
                groups.insert(key);
            }
    
            return groups.size();
        }
    };