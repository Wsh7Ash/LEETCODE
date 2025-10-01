class Solution {
    public:
        vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
            vector<vector<int>> res;
            unordered_map<int, vector<int>> sizeToGroup;
    
            for(int i = 0; i < groupSizes.size(); i++){
                int size = groupSizes[i];
    
                sizeToGroup[size].push_back(i);
    
                if(sizeToGroup[size].size() == size){
                    res.push_back(sizeToGroup[size]);
                    sizeToGroup[size].clear();
                }
            }
            return res;
        }
    };