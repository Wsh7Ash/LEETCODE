class Solution {
    public:
        bool uniqueOccurrences(vector<int>& arr) {
            unordered_map<int, int> freqMap;
    
            for(int num : arr){
                freqMap[num]++;
            }   
    
            unordered_set<int> freqSet;
            for(auto& pair : freqMap){
                if(freqSet.find(pair.second) != freqSet.end()){
                    return false;
                }
                freqSet.insert(pair.second);
            }
            return true;
        }
    };