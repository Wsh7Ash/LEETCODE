class Solution {
    public:
        bool canConvertString(string s, string t, int k) {
            if(s.length() != t.length()) return false;
            int n = s.length();
            vector<int> shiftCount(26, 0);
    
            for(int i = 0; i < n; i++){
                if(s[i] != t[i]){
                    int shift = (t[i] - s[i] + 26) % 26;
                    shiftCount[shift]++;
                }
            }
    
            for(int shift = 1; shift < 26; shift++){
                if(shiftCount[shift] > 0){
                    if(shift > k) return false;
                    int maxUses = (k - shift) / 26 + 1;
                    if(maxUses < shiftCount[shift]){
                        return false;
                    }
                }
            }
            return true;
        }
    };