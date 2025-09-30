class Solution {
    private:
        vector<int> generateGrayCode(int n){
            if (n == 0) return {0};
    
            vector<int> res = {0, 1};
    
            for(int i = 2; i <= n; i++){
                int size = res.size();
                for(int j = size - 1; j >= 0; j--){
                    res.push_back(res[j] | (1 << (i - 1)));
                }
            }
            return res;
        }
        
    public:
        vector<int> circularPermutation(int n, int start) {
            vector<int> grayCode = generateGrayCode(n);
            int startIndex = 0;
            for(int i = 0; i < grayCode.size(); i++){
                if(grayCode[i] == start){
                    startIndex = i;
                    break;
                }
            }
    
            vector<int> res;
            for(int i = 0; i < grayCode.size(); i++){
                res.push_back(grayCode[(startIndex + i) % grayCode.size()]);
            }
            return res;
        }
    };