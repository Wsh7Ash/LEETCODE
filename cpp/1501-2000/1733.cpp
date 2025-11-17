class Solution {
    public:
        int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
            int m = languages.size();
            vector<set<int>> langSet(m);
            for(int i = 0; i < m; i++){
                for(int lang : languages[i]){
                    langSet[i].insert(lang);
                }
            }
            vector<pair<int, int>> prbF;
            for(const auto& f : friendships){
                int u = f[0] - 1;
                int v = f[1] - 1;
                bool canComm = false;
                for(int lang : languages[u]){
                    if(langSet[v].count(lang)){
                        canComm = true;
                        break;
                    }
                }
                if(!canComm){
                    prbF.push_back({u, v});
                }
            }
            if(prbF.empty()) return 0;
    
            int minUsers = INT_MAX;
            for(int l = 1; l <= n; l++){
                set<int> userToteach;
                for(const auto& f : prbF){
                    int u = f.first;
                    int v = f.second;
                    if(!langSet[u].count(l)){
                        userToteach.insert(u);
                    }
                    if(!langSet[v].count(l)){
                        userToteach.insert(v);
                    }
                }
                minUsers = min(minUsers, (int)userToteach.size());
            }
            return minUsers
        }
    };