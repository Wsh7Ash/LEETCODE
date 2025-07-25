class Solution {
    public:
        vector<int> diStringMatch(string s) {
            int n = s.size();
            vector<int> perm;
            int low = 0, high  = n;
            for(char c : s){
                if(c == 'I'){
                    perm.push_back(low);
                    low++;
                }else{
                    perm.push_back(high);
                    high--;
                }
            }
            perm.push_back(low);
            return perm;
        
        }
    };