class Solution {
    public:
        vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
            vector<int> maxFreq(26, 0);
            for(const string& word : words2){
                vector<int> curFreq(26, 0);
                for(char c : word){
                    curFreq[c - 'a']++;
                }
                for(int i = 0; i < 26; i++){
                    maxFreq[i] = max(maxFreq[i], curFreq[i]);
                }
            }
    
            vector<string> res;
            for(const string& word : words1){
                vector<int> wordFreq(26, 0);
                for(char c : word){
                    wordFreq[c - 'a']++;
    
                }
    
                bool universal = true;
                for(int i = 0; i < 26; i++){
                    if(wordFreq[i] < maxFreq[i]){
                        universal = false;
                        break;
                    }
                }
                if(universal){
                    res.push_back(word);
                }
            }
            return res;
        }
    };