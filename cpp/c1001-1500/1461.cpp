class Solution {
    public:
        bool hasAllCodes(string s, int k) {
            int n = s.length();
            if(n < k) return false;
    
            unordered_set<string> seen;
            for(int i = 0; i <= n - k; i++){
                string substring = s.substr(i, k);
                seen.insert(substring);
                if(seen.size() == (1 << k)) return true;
            }
            return seen.size() == (1 << k);
        }
    };