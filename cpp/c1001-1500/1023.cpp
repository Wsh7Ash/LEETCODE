class Solution {
    public:
        vector<bool> camelMatch(vector<string>& queries, string pattern) {
            vector<bool> res;
            for(const string& query : queries){
                res.push_back(matchPattern(query, pattern));
            }
            return res;
        }
    private:
        bool matchPattern(const string& query, const string& pattern){
            int i = 0;
            int j = 0;
            while(i < query.size()){
                if(j < pattern.size() && query[i] == pattern[j]){
                    i++;
                    j++;
                }else if(islower(query[i])){
                    i++;
                }else{
                    return false;
                }
            }
            return j == pattern.size();
        }
    };