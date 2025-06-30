class Solution {
    public:
        bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
            int md = abs(target[0])+abs(target[1]);
            for(const auto& g : ghosts){
                int gd = abs(g[0]-target[0])+abs(g[1]-target[1]);
                if(gd <= md){
                    return false;
                }
            }
            return true;
        }
    };