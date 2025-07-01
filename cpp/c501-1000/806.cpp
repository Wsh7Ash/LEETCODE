class Solution {
    public:
        vector<int> numberOfLines(vector<int>& widths, string s) {
            int ls = 1;
            int clw = 0;
            for(char c : s){
                int w = widths[c - 'a'];
                if(clw + w > 100){
                    ls++;
                    clw = w;
                }else{
                    clw += w;
                }
            }
            return {ls, clw};
        }
    };