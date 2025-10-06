class Solution {
    public:
        vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
            
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    
            for(int i = 0; i < mat.size(); i++){
                int soldiers = 0;
                for(int j = 0; j < mat[i].size(); j++){
                    soldiers += mat[i][j];
                }
                pq.push({soldiers, i});
            }
    
            vector<int> res;
            for(int i = 0; i < k ; i++){
                res.push_back(pq.top().second);
                pq.pop();
            }
    
            return res;
        }
    };