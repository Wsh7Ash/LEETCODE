class Solution {
    public:
        bool isSub(string& word, string& s){
            int i = 0, j = 0;
            while(i < word.size() && j < s.size()){
                if(word[i] == s[j]){
                    i++;
                }
                j++;
            }
            return i == word.size();
        }
        string findLongestWord(string s, vector<string>& dictionary) {
            string res = "";
            for(string& word : dictionary){
                if(isSub(word, s)){
                    if(word.size() > res.size() || (word.size() == res.size() && word < res)){
                        res = word;
                    }
                }
            }
            return res;
        }
    };