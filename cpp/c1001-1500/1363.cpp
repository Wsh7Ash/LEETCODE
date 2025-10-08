class Solution {

    private:
        string convertToString(vector<int>& digits){
            if(digits.empty()){
                return "";
            }
    
            string res = "";
            for(int digit : digits){
                res += to_string(digit);
            }
    
            if(res[0] == '0') return "0";
    
            return res;
        }
    
        bool removeDigitsWithRemainder(vector<int>& digits, int remainder, int count){
    
            for(int i = digits.size() - 1; i >= 0 && count > 0; i--){
                if(digits[i] % 3 == remainder){
                    digits.erase(digits.begin() + i);
                    count--;
                }
            }    
    
            return count == 0;
        }
    
    public:
        string largestMultipleOfThree(vector<int>& digits) {
            
            sort(digits.begin(), digits.end(), greater<int>());
    
            int sum = 0; 
            for(int digit : digits){
                sum += digit;
            }
    
            if(sum % 3 == 0){
                return convertToString(digits);
            }
    
            if(sum % 3 == 1){
                if(removeDigitsWithRemainder(digits,1,1) || removeDigitsWithRemainder(digits,2,2)){
                    return convertToString(digits);
                }
            }else{
                if(removeDigitsWithRemainder(digits,2,1) || removeDigitsWithRemainder(digits,1,2)){
                    return convertToString(digits);
                }
            }
    
            return "";
        }
    };