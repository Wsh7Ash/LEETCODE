class Solution {
    public:
        string longestDupSubstring(string s) {
            int n = s.size();
            int left = 1, right = n;
            string res;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int pos = search(s, mid);
                if (pos != -1) {
                    res = s.substr(pos, mid);
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return res;
        }
    
    private:
        int search(const string& s, int len) {
            if (len == 0) return -1;
            
            const long long base = 256;
            const long long mod = 1e9 + 7;
            
            long long hash = 0;
            long long power = 1;
            
            for (int i = 0; i < len; i++) {
                hash = (hash * base + s[i]) % mod;
                if (i < len - 1) {
                    power = (power * base) % mod;
                }
            }
            
            unordered_map<long long, vector<int>> hashToIndices;
            hashToIndices[hash].push_back(0);
            
            for (int i = len; i < s.size(); i++) {
                hash = (hash - (s[i - len] * power) % mod + mod) % mod;
                hash = (hash * base + s[i]) % mod;
                
                if (hashToIndices.find(hash) != hashToIndices.end()) {
                    string current = s.substr(i - len + 1, len);
                    for (int idx : hashToIndices[hash]) {
                        if (s.substr(idx, len) == current) {
                            return idx; 
                        }
                    }
                }
                hashToIndices[hash].push_back(i - len + 1);
                
                if (hashToIndices.size() > 100000) {
                    hashToIndices.clear();
                    hashToIndices[hash].push_back(i - len + 1);
                }
            }
            return -1;
        }
    };