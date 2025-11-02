#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> sumIndices;
        for(int i = 0; i < n; i++){
            sumIndices.push_back({aliceValues[i] + bobValues[i], i});
        }
        sort(sumIndices.begin(), sumIndices.end(), greater<pair<int, int>>());
        int aliceScore = 0, bobScore = 0;
        for(int i = 0; i < n; i++){
            int index = sumIndices[i].second;
            if(i % 2 == 0){
                aliceScore += aliceValues[index];
            }else{
                bobScore += bobValues[index];
            }
        }
        if(aliceScore > bobScore){
            return 1;
        }else if(aliceScore < bobScore){
            return -1;
        }else{
            return 0;
        }
    }
};