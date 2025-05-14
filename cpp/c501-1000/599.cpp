class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        vector<string> res;
        int minSum = INT_MAX;

        for(int i = 0; i < list1.size(); i++){
            map[list1[i]] = i;
        }

        for(int j = 0; j <list2.size(); j++){
            if(map.find(list2[j]) != map.end()){
                int sum = j + map[list2[j]];
                if(sum < minSum){
                    minSum = sum;
                    res.clear();
                    res.push_back(list2[j]);
                }else if(sum == minSum){
                    res.push_back(list2[j]);
                }
            }
        }
        return res;
    }
};