class Solution {
    public:
        vector<string> uncommonFromSentences(string s1, string s2) {
            unordered_map<string, int> wordCount;
    
            istringstream iss1(s1);
            string word;
            while(iss1 >> word) wordCount[word]++;
            istringstream iss2(s2);
            while(iss2 >> word) wordCount[word]++;
    
            vector<string> res;
            for(const auto& pair : wordCount){
                if(pair.second == 1) res.push_back(pair.first);
            }
            return res;
        }
    };