class Solution {
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            int l = 0;
            int r = letters.size() - 1;
    
            while(l <= r){
                int m = l + (r - l) / 2;
                if(letters[m] > target){
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
            return l < letters.size() ? letters[l] : letters[0];
        }
    };