class Solution {
    public:
        vector<string> findRelativeRanks(vector<int>& score) {
            int n = score.size();
            vector<pair<int, int>> indexedScores;
            for(int i =0; i < n; i++){
                indexedScores.emplace_back(score[i], i);
            }
            sort(indexedScores.begin(), indexedScores.end(), [](const pair<int, int>& a, const pair<int, int>& b){
                return a.first > b.first;
            });
    
            vector<string> res(n);
            for(int i = 0; i < n; i++){
                int originalIndex = indexedScores[i].second;
                if(i == 0){
                    res[originalIndex] = "Gold Medal";
                }
                else if(i == 1){
                    res[originalIndex] = "Silver Medal";
                }
                else if(i == 2){
                    res[originalIndex] = "Bronze Medal";
                }
                else{
                    res[originalIndex] = to_string(i + 1);
                }
            }
            return res;
        }
    };