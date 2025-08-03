class Solution {
    public:
        bool queryString(string s, int n) {
            for(int i = 1; i <= n; i++){
                string binary = convertToBinary(i);
                if(s.find(binary) == string::npos){
                    return false;
                }
            }
            return true;
        }
    private:
        string convertToBinary(int num){
            string binary;
            while(num > 0){
                binary += (num % 2) ? '1' : '0';
                num /= 2;
            }
            reverse(binary.begin(), binary.end());
            return binary;
        }
    };