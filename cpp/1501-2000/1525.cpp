class Solution {
    public:
        int numSplits(string s) {
            int n = s.length();
            vector<int> left(26, 0), right(26, 0);
            int leftCount = 0, rightCount = 0;
    
            for(char c : s){
                right[c - 'a']++;
                if(right[c - 'a'] == 1){
                    rightCount++;
                }
            }
    
            int res = 0;
            for(int i = 0; i < n; i++){
                char c = s[i];
                left[c - 'a']++;
                if(left[c - 'a']==1){
                    leftCount++;
                }
                right[c-'a']--;
                if(right[c-'a'] == 0){
                    rightCount--;
                }
    
                if(leftCount == rightCount){
                    res++;
                }
            }
            return res;
        }
    };