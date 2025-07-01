class Solution {
    public:
        int expressiveWords(string s, vector<string>& words) {
            vector<pair<char, int>> sGroups = getGroups(s);
            int res = 0;
            for(const string& word : words){
                vector<pair<char, int>> wordGroups = getGroups(word);
                if(sGroups.size() != wordGroups.size()) continue;
                bool valid = true;
                for(int i = 0; i < sGroups.size(); i++){
                    if(sGroups[i].first != wordGroups[i].first){
                        valid = false;
                        break;
                    }
                    int sCount = sGroups[i].second;
                    int wCount = wordGroups[i].second;
                    if(wCount > sCount || (sCount < 3 && wCount != sCount)){
                        valid = false;
                        break;
                    }
                }
                if(valid) res++;
            }
            return res;
        }
    
        vector<pair<char, int>> getGroups(const string& s){
            vector<pair<char, int>> groups;
            if(s.empty()) return groups;
            char cur = s[0];
            int count = 1;
            for(int i = 1; i < s.size(); i++){
                if(s[i] == cur){
                    count++;
                }else{
                    groups.emplace_back(cur, count);
                    cur = s[i];
                    count = 1;
                }
            }
            groups.emplace_back(cur, count);
            return groups;
        }
    };