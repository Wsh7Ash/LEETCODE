class Solution {
    public:
        int numMatchingSubseq(string s, vector<string>& words) {
            unordered_map<char, vector<int>> charIndices;
            for(int i = 0; i < s.size(); i++){
                charIndices[s[i]].push_back(i);
            }
            int count = 0;
            for(const string& word : words){
                int curpos = -1;
                bool isSubseq = true;
                for(char c : word){
                    auto it = upper_bound(charIndices[c].begin(), charIndices[c].end(), curpos);
                    if(it == charIndices[c].end()){
                        isSubseq = false;
                        break;
                    }
                    curpos = *it;
                }
                if(isSubseq){
                    count++;
                }
            }
            return count;
        }
    };