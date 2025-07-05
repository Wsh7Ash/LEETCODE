class Solution {
    public:
        int uniqueLetterString(string s) {
            unordered_map<char, vector<int>> charIndices;
            for(int i = 0; i < s.size(); i++){
                char c = s[i];
                charIndices[c].push_back(i);
            }
    
            int res  = 0;
            for(auto& e : charIndices){
                const vector<int>& indices = e.second;
                int n = indices.size();
                for(int i = 0; i < n; i++){
                    int l = i == 0 ? -1 : indices[i-1];
                    int r = i == n - 1 ? s.size() : indices[i+1];
                    int cur = indices[i];
                    res += (cur  - l) * ( r - cur);
                }
            }
            return res;
        }
    };