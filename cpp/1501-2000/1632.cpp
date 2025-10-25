class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<int, vector<pair<int, int>>> groups;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                groups[matrix[i][j]].emplace_back(i, j);
            }
        }
        vector<int> rankRow(m, 0);
        vector<int> rankCol(n, 0);
        vector<vector<int>> res(m, vector<int>(n));

        for(auto& [val, pos] : groups){
            vector<int> parent(m + n);
            for(int i = 0; i < m + n; i++){
                parent[i] = i;
            }
            function<int(int)> find = [&](int x){
                if(parent[x] != x) parent[x] = find(parent[x]);
                return parent[x];
            };
            for(auto& [i, j] : pos){
                int rootI = find(i);
                int rootJ = find(j + m);
                if(rootI != rootJ){
                    parent[rootJ] = rootI;
                }
            }
            unordered_map<int, int> groupMaxRank;
            for(auto& [i, j] : pos){
                int root = find(i);
                int reqRank = max(rankRow[i], rankCol[j]) + 1;
                groupMaxRank[root] = max(groupMaxRank[root], reqRank); 
            }
            for(auto& [i, j] : pos){
                int root = find(i);
                int rankVal = groupMaxRank[root];
                res[i][j] = rankVal;
                rankRow[i] = max(rankRow[i], rankVal);
                rankCol[j] = max(rankCol[j], rankVal);
            }
        }
        return res;
    }
};