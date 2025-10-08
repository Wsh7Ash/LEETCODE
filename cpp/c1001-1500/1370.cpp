class Solution {
    public:
        string sortString(string s) {
            
            vector<int> count(26,0);
            for(char c : s){
                count[c - 'a']++;
            }
    
            string res = "";
    
            while(res.length() < s.length()){
                for(int i = 0; i < 26; i++){
                    if(count[i] > 0){
                        res += (char)('a' + i);
                        count[i]--;
                    }
                }
    
                for(int i = 25; i >=0; i--){
                    if(count[i] > 0){
                        res += (char)('a' + i);
                        count[i]--;
                    }
                }
            }
    
            return res;
        }
    };