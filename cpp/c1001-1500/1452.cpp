class Solution {
    public:
        vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
            int n = favoriteCompanies.size();
    
            vector<unordered_set<string>> companySets(n);
            for(int i = 0; i < n; i++){
                companySets[i] = unordered_set<string>(favoriteCompanies[i].begin(), favoriteCompanies[i].end());
            }
    
            vector<int> res;
    
            for(int i = 0; i < n; i++){
                bool isSubset = false;
                for(int j = 0; j < n; j++){
                    if(i == j) continue;
    
                    if(companySets[i].size() > companySets[j].size()) continue;
    
                    bool subset = true;
                    for(const string& company : companySets[i]){
                        if(companySets[j].find(company) == companySets[j].end()){
                            subset = false;
                            break;
                        }
                    }
    
                    if(subset){
                        isSubset = true;
                        break;
                    }
                }
                if(!isSubset){
                    res.push_back(i);
                }
            }
    
            return res;
        }
    };