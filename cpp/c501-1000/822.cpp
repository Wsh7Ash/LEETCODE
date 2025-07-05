class Solution {
    public:
        int flipgame(vector<int>& fronts, vector<int>& backs) {
            unordered_set<int> invalid;
            for(int i = 0; i < fronts.size(); i++){
                if(fronts[i] == backs[i]){
                    invalid.insert(fronts[i]);
                }
            }
            int min_good = INT_MAX;
            for(int num : fronts){
                if(invalid.find(num) == invalid.end()){
                    min_good = min(min_good, num);
                }
            }
            
            for(int num : backs){
                if(invalid.find(num) == invalid.end()){
                    min_good = min(min_good, num);
                }
            }
            return min_good == INT_MAX ? 0 : min_good;
            
        }
    };