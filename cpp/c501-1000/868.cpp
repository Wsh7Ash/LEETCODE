class Solution {
    public:
        int binaryGap(int n) {
            vector<int> ones;
            int pos = 0;
            while(n > 0){
                if(n & 1){
                    ones.push_back(pos);
                }
                n >>= 1;
                pos++;
            }
            if(ones.size() < 2) return 0;
            int md = 0;
            for(int i = 1; i < ones.size(); i++){
                md = max(md, ones[i] - ones[i-1]);
    
            }
            return md;
        }
    };