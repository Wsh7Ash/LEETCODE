class Solution {
    public:
        vector<string> commonChars(vector<string>& words) {
            vector<string> res;
            if(words.empty()) return res;
    
            map<char, int> minFreq;
            for(char c : words[0]) minFreq[c]++;
    
            for(const string& word : words){
                map<char, int> curFreq;
                for(char c : word) curFreq[c]++;
                for(auto it = minFreq.begin(); it != minFreq.end(); ){
                    char key = it->first;
                    if(curFreq.find(key) != curFreq.end()){
                        it->second = min(it->second, curFreq[key]);
                        it++;
                    }else{
                        it = minFreq.erase(it);
                    }
                }
            }
    
            for(const auto& entry : minFreq){
                for(int i = 0; i < entry.second; i++){
                    res.push_back(string(1, entry.first));
                }
            }
            return res;
        }
    };