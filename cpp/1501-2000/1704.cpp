class Solution {
    public:
        bool halvesAreAlike(string s) {
            int n = s.length();
            int mid = n / 2;
            unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
            int countA = 0;
            for(int i = 0; i < mid; i++){
                if(vowels.find(s[i]) != vowels.end()){
                    countA++;
                }
            }
            int countB = 0;
            for(int i = mid; i < n; i++){
                if(vowels.find(s[i]) != vowels.end()){
                    countB++;
                }
            }
            return countA == countB;
        }
    };