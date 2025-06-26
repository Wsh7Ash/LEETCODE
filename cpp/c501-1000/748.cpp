class Solution {
    public:
        string shortestCompletingWord(string licensePlate, vector<string>& words) {
           unordered_map<char, int> lc;
           for(char c : licensePlate) {
            if(isalpha(c)){
                char lC = tolower(c);
                lc[lC]++;
            }
           }
           string res;
           int ml = INT_MAX;
    
           for(const string& w : words){
            unordered_map<char, int> wc;
            for(char c : w){
                wc[c]++;
            }
            bool iv = true;
            for(const auto& p : lc){
                if(wc[p.first] < p.second){
                    iv = false;
                    break;
                }
            }
            if(iv && w.length() < ml){
                ml = w.length();
                res = w;
            }
           }
           return res;
        }
    };