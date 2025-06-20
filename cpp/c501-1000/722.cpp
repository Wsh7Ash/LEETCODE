class Solution {
    public:
        vector<string> removeComments(vector<string>& source) {
            vector<string> res;
            bool inBlock = false;
            string buffer;
    
            for(string line : source){
                int i = 0;
                int n = line.size();
                if(!inBlock) buffer.clear();
                while(i < n){
                    if(!inBlock && i + 1 < n && line[i] == '/' && line[i + 1] == '*'){
                        inBlock = true;
                        i += 2;
                    }
                    else if(inBlock && i + 1 < n && line[i] == '*' && line[i + 1] == '/'){
                        inBlock = false;-
                        i += 2;
                    }
                    else if(!inBlock && i + 1 < n && line[i] == '/' && line[i + 1] == '/'){
                        break;
                    }
                    else if(!inBlock){
                        buffer += line[i];
                        i++;
                    }
                    else{
                        i++;
                    }
                }
                if(!inBlock && !buffer.empty()){
                    res.push_back(buffer);
                }
            }
            return res;
        }
    };