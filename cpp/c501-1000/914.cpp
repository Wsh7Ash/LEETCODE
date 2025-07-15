class Solution {
    public:
        bool hasGroupsSizeX(vector<int>& deck) {
            unordered_map<int, int> freq;
            for(int card : deck){
                freq[card]++;
            }
    
            int common_gcd = 0;
            for(const auto& pair : freq){
                if(common_gcd == 0){
                    common_gcd = pair.second;
                }else{
                    common_gcd = gcd(common_gcd, pair.second);
                }
            }
            return common_gcd >= 2;
        }
    
        int gcd(int a, int b){
            while(b != 0){
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
    };