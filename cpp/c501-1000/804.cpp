class Solution {
    public:
        int uniqueMorseRepresentations(vector<string>& words) {
            vector<string> morseCodes = {
                ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
            };
    
            unordered_set<string> t;
            for(const string& w : words){
                string mw;
                for(char c : w){
                    mw += morseCodes[c - 'a'];
                }
                t.insert(mw);
            }
            return t.size();
        }
    };