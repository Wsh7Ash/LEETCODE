class Solution {
    public:
        string getHappyString(int n, int k) {
            int total = 3 * (1 << (n - 1));
            if(k > total) return "";
    
            string res;
            for(int i = 0; i < n; i++){
                int branchSize = 1 << (n - i - 1);
                for(char c : {'a', 'b', 'c'}){
                    if(!res.empty() && res.back() == c) continue;
                    if(k > branchSize){
                        k -= branchSize;
                    }else{
                        res.push_back(c);
                        break;
                    }
                }
            }
            return res;
        }
    };