string expandAroundCenter(string s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }

    string longestPalindrome(string s) {
        if(s.empty()) return "";

        string longest;
        for(int i = 0; i < s.size(); i++){
            string odd = expandAroundCenter(s,i,i);
            if(odd.size() > longest.size()) longest = odd;
            string even = expandAroundCenter(s,i,i + 1);
            if(even.size() > longest.size()) longest = even;
        }   
        return longest;
    }