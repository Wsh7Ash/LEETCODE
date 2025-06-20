class DSU {
public:
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY){
            parent[rootY] = rootX;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToIndex;
        unordered_map<int, string> indexToEmail;
        int n = accounts.size();
        DSU dsu(10000);

        int id= 0;
    for(int i = 0; i< n; i++){
        string name = accounts[i][0];
        for(int j = 1; j < accounts[i].size(); j++){
            string email = accounts[i][j];
            if(emailToIndex.find(email) == emailToIndex.end()){
                emailToIndex[email] = id;
                indexToEmail[id] = name;
                id++;
            }
            dsu.unite(emailToIndex[accounts[i][1]], emailToIndex[email]);
        }
    }
    unordered_map<int, set<string>> mergedEmails;
    for(auto& pair : emailToIndex){
        string email = pair.first;
        int index = pair.second;
        int root = dsu.find(index);
        mergedEmails[root].insert(email);
    }
    vector<vector<string>> res;
    for(auto& pair : mergedEmails){
        int root = pair.first;
        vector<string> emails(pair.second.begin(), pair.second.end());
        sort(emails.begin(), emails.end());
        emails.insert(emails.begin(), indexToEmail[root]);
        res.push_back(emails);
    }
    return res;
    }
    
};