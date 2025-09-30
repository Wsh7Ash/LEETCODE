class Solution {
    public:
        int maxLength(vector<string>& arr) {
            vector<int> masks;
            vector<int> lens;
    
            for(const string& s : arr){
                int mask = 0;
                bool valid = true;
    
                for(char c : s){
                    int bit = 1 << (c - 'a');
                    if(mask & bit){
                        valid = false;
                        break;
                    }
                    mask |= bit;
                }
                if(valid){
                    masks.push_back(mask);
                    lens.push_back(s.length());
                }
            }
    
            return backtrackBitmask(masks, lens, 0, 0);
        }
    private:
        int backtrackBitmask(const vector<int>& masks, const vector<int>& lens, int index, int curMask){
            int maxlen = __builtin_popcount(curMask);
            for(int i = index; i < masks.size(); i++){
                if((curMask & masks[i]) == 0){
                    maxlen = max(maxlen, backtrackBitmask(masks, lens, i + 1, curMask | masks[i]));
                }
            }
            return maxlen;
        }
    };