class Solution {
    public:
        int maxRepeating(string sequence, string word) {
            int maxK = 0;
            string repeating = word;
            while(sequence.find(repeating) != string::npos){
                maxK++;
                repeating += word;
            }   
            return maxK;
        }
    };