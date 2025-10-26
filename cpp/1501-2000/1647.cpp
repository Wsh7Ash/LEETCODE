class Solution {
    public:
        int minDeletions(string s) {
            vector<int> freq(26, 0);
            for(char c : s){
                freq[c - 'a']++;
            }
            sort(freq.begin(), freq.end(), greater<int>());
            int maxAllowed = s.length();
            int deletions = 0;
            for(int f : freq){
                if(f == 0) break;
                if(f > maxAllowed){
                    deletions += (f - maxAllowed);
                    f = maxAllowed;
                }
                maxAllowed = max(0, f - 1);
            }
            return deletions;
        }
    };