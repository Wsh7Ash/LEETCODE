class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(s,0, seen);
    }
private:
    int backtrack(const string& s, int start, unordered_set<string>& seen){
        if(start == s.length()) return 0;
        int maxSplits = 0;
        for(int end = start + 1; end <= s.length(); end++){
            string substring = s.substr(start, end - start);
            if(seen.find(substring) == seen.end()){
                seen.insert(substring);
                int remSplits = backtrack(s, end, seen);
                maxSplits = max(maxSplits, 1 + remSplits);
                seen.erase(substring);
            }
        }
        return maxSplits;
    }
};