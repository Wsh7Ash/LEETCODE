class Solution {
    public:
        vector<int> processQueries(vector<int>& queries, int m) {
            vector<int> P(m);
            vector<int> res;
    
            for(int i = 0; i < m; i++){
                P[i] = i + 1;
            }
    
            for(int query : queries){
                int pos = -1;
                for(int i = 0; i < m; i++){
                    if(P[i] == query){
                        pos = i;
                        break;
                    }
                }
                res.push_back(pos);
                
                for(int i = pos; i > 0; i--){
                    P[i] = P[i - 1];
                }
                P[0] = query;
            }
            return res;
        }
    };