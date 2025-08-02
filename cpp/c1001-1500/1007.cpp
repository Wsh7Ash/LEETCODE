class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int n = tops.size();
            int res = INT_MAX;
    
            for(int target : {tops[0], bottoms[0]}){
                int top_rotations = 0;
                int bottom_rotations = 0;
                bool possible = true;
    
                for(int i = 0; i < n; i++){
                    if(tops[i] != target && bottoms[i] != target){
                        possible = false;
                        break;
                    }
                    if(tops[i] != target) top_rotations++;
                    if(bottoms[i] != target) bottom_rotations++;
                } 
                if(possible) res = min(res, min(top_rotations, bottom_rotations));
            }
            return res == INT_MAX ? -1 : res;
        }
    };