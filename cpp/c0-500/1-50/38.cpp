class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for(int i = 2; i <= n; i++){
            string temp = "";
            int count = 1;
            for(int j = 1; j < result.length(); j++){
                if(result[j] == result[j - 1]){
                    count++;
                }else{
                    temp += to_string(count) + result[j -1];
                    count = 1;
                }
            }
            temp += to_string(count) + result[result.length() - 1];
            result = temp;
        }
        return result;
    }
};