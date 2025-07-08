class Solution {
    public:
        bool isNStraightHand(vector<int>& hand, int groupSize) {
            if(hand.size() % groupSize != 0) return false;
    
            map<int, int> countMap;
            for(int  card : hand){
                countMap[card]++;
            }
    
            while(!countMap.empty()){
                int s = countMap.begin()->first;
                for(int i = 0; i < groupSize; i++){
                    int cur = s + i;
                    if(countMap.find(cur) == countMap.end()){
                        return false;
                    }
                    if(--countMap[cur] == 0){
                        countMap.erase(cur);
                    }
                }
            }
            return true;
        }
    };