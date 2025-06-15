class Solution {
    public:
        vector<int> fallingSquares(vector<vector<int>>& positions) {
            vector<int> res;
            vector<pair<int, int>> ins;
            vector<int> hs;
            int mh = 0;
    
            for(const auto& pos : positions){
                int l = pos[0];
                int s = pos[1];
                int r = l + s;
                int cmh = 0;
    
                for(int i = 0; i < ins.size(); i++){
                    int ss = ins[i].first;
                    int e = ins[i].second;
                    if(!(r <= ss || l >= e)){
                        cmh = max(cmh, hs[i]);
                    }
                }
                int nh = cmh + s;
                ins.push_back({l, r});
                hs.push_back(nh);
                mh = max(mh, nh);
                res.push_back(mh);
            }
            return res;
        }
    };