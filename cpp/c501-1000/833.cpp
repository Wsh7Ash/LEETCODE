class Solution {
    public:
        string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
            unordered_map<int, pair<int, string>> replacements;
            for(int i = 0; i < indices.size(); i++){
                int index = indices[i];
                string source = sources[i];
                if(s.substr(index, source.size()) == source){
                    replacements[index] = {source.size(), targets[i]};
                }
            }
    
            string res;
            int i =0;
            while(i < s.size()){
                if(replacements.count(i)){
                    res += replacements[i].second;
                    i+= replacements[i].first;
                }else{
                    res += s[i];
                    i++;
                }
            }
            return res;
        }
    };