class Solution {
    public:
        vector<string> topKFrequent(vector<string>& words, int k) {
            unordered_map<string, int> fm;
            for(const string& word : words){
                fm[word]++;
            }
            vector<pair<string, int>> fv(fm.begin(), fm.end());
            sort(fv.begin(), fv.end(), [](const pair<string, int>& a, const pair<string, int>& b){
                if(a.second == b.second) return a.first < b.first;
                else return a.second > b.second;
            });
    
            vector<string> res;
            for(int i = 0; i < k; i++){
                res.push_back(fv[i].first);
            }
            return res;
        }
    };