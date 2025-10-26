class Solution {
    public:
        bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
            int w1 = 0, c1 = 0;
            int w2 = 0, c2 = 0;
    
            while(w1 < word1.size() && w2 < word2.size()){
                if(word1[w1][c1] != word2[w2][c2]){
                    return false;
                }
                c1++;
                c2++;
                if(c1 == word1[w1].size()){
                    w1++;
                    c1 = 0;
                }
                if(c2 == word2[w2].size()){
                    w2++;
                    c2 = 0;
                }
            }
    
            return w1 == word1.size() && w2 == word2.size();
        }
    };