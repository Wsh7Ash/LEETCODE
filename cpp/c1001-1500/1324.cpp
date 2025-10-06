class Solution {
    public:
        vector<string> printVertically(string s) {
            vector<string> words;
            stringstream ss(s);
            string word;
    
            while(ss >> word){
                words.push_back(word);
            }
    
            int maxLen = 0;
            for(const string& w : words){
                maxLen = max(maxLen, (int)w.length());
            }
    
            vector<string> res(maxLen, "");
    
            for(int i = 0; i < maxLen; i++){
                for(const string& w :  words){
                    if(i < w.length()){
                        res[i] += w[i];
                    }else{
                        res[i] += ' ';
                    }
                }
    
                while(!res[i].empty() && res[i].back() == ' '){
                    res[i].pop_back();
                }
            }
            return res;
        }
    };