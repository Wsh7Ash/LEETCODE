class Solution {
    public:
        bool pyramidTransition(string bottom, vector<string>& allowed) {
            unordered_map<string, vector<char>> patternMap;
            for(const string& pattern : allowed){
                string key = pattern.substr(0, 2);
                patternMap[key].push_back(pattern[2]);
            }
            unordered_map<string, bool> memo;
            return dfs(bottom, patternMap, memo);
        }
    
        bool dfs(const string& current, unordered_map<string, vector<char>>& patternMap, unordered_map<string, bool>& memo) {
            if(current.size() == 1) return true;
            if(memo.find(current) != memo.end()) return memo[current];
            
            string next;
            vector<string> possibleLevels;
            generatePossibleLevels(current, 0, next, possibleLevels, patternMap);
            
            for(const string& level : possibleLevels) {
                if(dfs(level, patternMap, memo)) {
                    memo[current] = true;
                    return true;
                }
            }
            
            memo[current] = false;
            return false;
        }
    
        void generatePossibleLevels(const string& current, int index, string next, vector<string>& possibleLevels, unordered_map<string, vector<char>>& patternMap) {
            if(index == current.size() - 1) {
                possibleLevels.push_back(next);
                return;
            }
            string key = current.substr(index, 2);
            if(patternMap.find(key) == patternMap.end()) return;
            for(char c : patternMap[key]) {
                generatePossibleLevels(current, index + 1, next + c, possibleLevels, patternMap);
            }
        }
    };