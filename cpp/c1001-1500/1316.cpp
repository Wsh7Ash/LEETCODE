class Solution {
    public:
        int distinctEchoSubstrings(string text) {
            int n = text.length();
            unordered_set<string> seen;
    
            for(int i = 0; i < n; i++){
                for(int l = 1; i + 2 * l <= n; l++){
                    if(text[i] == text[i + l] && text[i + l - 1] == text[i + 2 * l - 1]){
                        bool match = true;
                        for(int k = 0; k < l; k++){
                            if(text[i + k] != text[i + l + k]){
                                match = false;
                                break;
                            }
                        }
                        if(match){
                            seen.insert(text.substr(i, 2 * l));
                        }
                    }
                }
            }
            return seen.size();
        }
    };