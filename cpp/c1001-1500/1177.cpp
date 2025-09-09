class Solution {
    public:
        vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
            int n = s.length();
            vector<vector<int>> prefix(26, vector<int>(n+1, 0));
    
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < n; j++){
                    prefix[i][j+1] = prefix[i][j] + (s[j] - 'a' == i); 
                }
            }
    
            vector<bool> res;
            for(auto& q : queries){
                int l = q[0], r = q[1], k = q[2];
                int odd_count = 0;
                for(int i = 0; i < 26; i++){
                    int count = prefix[i][r+1] - prefix[i][l];
                    if(count % 2 == 1){
                        odd_count++;
                    }
                }
    
                int req = odd_count / 2;
                if(k >= req) res.push_back(true);
                else res.push_back(false);
            }
    
            return res;
        }
    };