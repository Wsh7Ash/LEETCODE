class Solution {
    public:
        string entityParser(string text) {
            unordered_map<string, char> entityMap = {
                {"&quot;", '"'},
                {"&apos;", '\''},
                {"&amp;", '&'},
                {"&gt;", '>'},
                {"&lt;", '<'},
                {"&frasl;", '/'}
            };
    
            string res;
            int n = text.length();
            int i = 0;
            
            while(i < n){
                if(text[i] == '&'){
                    bool found = false;
                    for(const auto& [entity, replacement] : entityMap){
                        int len = entity.length();
                        if(i + len <= n && text.substr(i, len) == entity){
                            res += replacement;
                            i += len;
                            found = true;
                            break;
                        }
                    }
    
                    if(!found){
                        res += '&';
                        i++;
                    }
                }else{
                    res += text[i];
                    i++;
                }
            }
            return res;
        }
    };