class Solution {
    public:
        string orderlyQueue(string s, int k) {
            if(k == 1){
                string min_str = s;
                for(int i = 0; i < s.size(); i++){
                    rotate(s.begin(), s.begin() + 1, s.end());
                    if(s < min_str){
                        min_str = s;
                    }
                }
                return min_str;
            }else{
                sort(s.begin(), s.end());
                return s;
            }
        }
    };