class Solution {
    public:
        int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
            unordered_map<string, int> patternCount;
            int maxRows = 0;
    
            for(const auto& row : matrix){
                string pattern;
                string complementPattern;
    
                for(int num : row){
                    pattern += to_string(num);
                    complementPattern += to_string(1 - num);
                }
                patternCount[pattern]++;
                maxRows = max(maxRows, patternCount[pattern] + patternCount[complementPattern]);
            }
            return maxRows;
        }
    };