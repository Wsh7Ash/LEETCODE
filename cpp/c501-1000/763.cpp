class Solution {
    public:
        vector<int> partitionLabels(string s) {
            unordered_map<char, int> lo;
            for(int i = 0; i < s.size(); i++){
                lo[s[i]] = i;
            }
            vector<int> ps;
            int st = 0;
            int e = 0;
    
            for(int i = 0; i < s.size(); i++){
                e = max(e, lo[s[i]]);
                if(i == e){
                    ps.push_back(e-st+1);
                    st = e + 1;
                }
            }
            return ps;
        }
    };