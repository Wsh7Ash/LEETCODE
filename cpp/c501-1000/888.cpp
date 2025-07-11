class Solution {
    public:
        vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
            int sumAlice = 0, sumBob = 0;
            for(int num :  aliceSizes){
                sumAlice += num;
            }
            for(int num :  bobSizes){
                sumBob += num;
            }
            int delta = (sumBob - sumAlice) / 2;
    
            unordered_set<int> bobSet;
            for(int num : bobSizes){
                bobSet.insert(num);
            }
            for(int num : aliceSizes){
                if(bobSet.count(num + delta)){
                    return {num, num + delta};
                }
            }
            return {};
        }
    };