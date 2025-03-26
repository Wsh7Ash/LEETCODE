int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> charSet;
        int j = 0;
        int maxlen = 0;

        for(int i = 0; i < n; i++){
            while(charSet.find(s[i]) != charSet.end()){
                charSet.erase(s[j]);
                j++;
            }
            charSet.insert(s[i]);
            maxlen = max(maxlen, i - j + 1);
        }
        return maxlen;
    }