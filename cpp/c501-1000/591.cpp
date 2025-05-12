class Solution {
    public:
        bool isValid(string code) {
            stack<string> tags;
            int i = 0;
            int n = code.size();
            while(i < n){
                if(i > 0 && tags.empty()) return false;
                if(code[i] == '<'){
                    if(i + 1 < n && code[i+1] == '!'){
                        if(i + 9 >= n) return false;
                        string cdata = code.substr(i, 9);
                        if(cdata != "<![CDATA[") return false;
                        i+=9;
                        int end = code.find("]]>", i);
                        if(end ==  string::npos) return false;
                        i = end + 3;
                    }else if(i + 1 < n && code[i+1] == '/'){
                        int j = code.find('>', i);
                        if(j == string::npos) return false;
                        string tagName = code.substr(i + 2, j - (i + 2));
                        if(tags.empty() || tags.top() != tagName) return false;
                        tags.pop();
                        i = j + 1; 
                    }else{
                        int j = code.find('>', i);
                        if(j == string::npos) return false;
                        string tagName = code.substr(i + 1, j - (i + 1));
                        if(tagName.empty() || tagName.size() > 9) return false;
                        for(char c : tagName){
                            if(!isupper(c)) return false;
                        }
                        tags.push(tagName);
                        i = j + 1;
                    }
                }else{
                    i++;
                }
            }
            return tags.empty();
        }
    };