class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramsGroups;

        for(string word : strs){
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            anagramsGroups[sortedWord].push_back(word);
        }
        vector<vector<string>> result;
        for(auto& group : anagramsGroups){
            result.push_back(group.second);
        }
        return result;
    }
};