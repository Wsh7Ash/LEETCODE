class Solution {
    public:
        int numJewelsInStones(string jewels, string stones) {
            unordered_set<char> js(jewels.begin(), jewels.end());
            int c = 0;
            for(char s : stones){
                if(js.count(s)){
                    c++;
                }
            }
            return c;
        }
    };