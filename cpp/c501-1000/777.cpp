class Solution {
    public:
        bool canTransform(string start, string result) {
           if(start.size() != result.size()) return false;
    
           int n = start.size();
           vector<pair<char, int>> startLR, resultLR;
    
           for(int i = 0; i < n; i++){
            if(start[i] != 'X'){
                startLR.emplace_back(start[i], i);
            }
            if(result[i] != 'X'){
                resultLR.emplace_back(result[i], i);
            }
           } 
           if(startLR.size() != resultLR.size()) return false;
    
           for(int i = 0; i < startLR.size(); i++){
            if(startLR[i].first != resultLR[i].first) return false;
            if(startLR[i].first == 'L' && startLR[i].second  < resultLR[i].second) return false;
            if(startLR[i].first == 'R' && startLR[i].second  > resultLR[i].second) return false;
           }
           return true;
        }
    };