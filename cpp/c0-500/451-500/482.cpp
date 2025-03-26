class Solution {
    public:
        string licenseKeyFormatting(string s, int k) {
            int charCount = 0;
            for(char c : s){
                if(c != '-') charCount++;
            }
    
            if(charCount == 0) return "";
            string result;
            int groupSize = 0;
    
            for(int i = s.length() - 1; i >= 0; i--){
                if(s[i] != '-'){
                    result += toupper(s[i]);
                    groupSize++;
    
                    
    
                    if(groupSize % k == 0){
                        result += '-';
                        groupSize = 0;
                    }
                }
            }
    
            if(!result.empty() && result.back() == '-') result.pop_back();
            
    
            reverse(result.begin(), result.end());
            return result;
        }
    };