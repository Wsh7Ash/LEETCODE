class Solution {
    public:
        int gcd(int a, int b){
            while(b != 0){
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
    
        int lcm(int a, int b){
            return a *  b / gcd(a, b);
        }
    
        string fractionAddition(string expression) {
            vector<pair<int, int>> fractions;
            int i = 0; 
            int n = expression.size();
            while(i < n){
                int sign = 1;
                if(expression[i] == '-'){
                    sign = -1;
                    i++;
                }else if(expression[i] == '+'){
                    sign = 1;
                    i++;
                }
                int numerator = 0;
                while(i < n && isdigit(expression[i])){
                    numerator = numerator * 10 + (expression[i] - '0');
                    i++;
                }
                numerator *= sign;
                i++;
                int denominator = 0;
                while(i < n && isdigit(expression[i])){
                    denominator = denominator * 10 + (expression[i] - '0');
                    i++;
                }
                fractions.emplace_back(numerator, denominator);
            }
            int common_denominator = 1;
            for(auto& frac : fractions){
                common_denominator = lcm(common_denominator, frac.second);
            }
            int total_numerator = 0;
            for(auto& frac : fractions){
                total_numerator += frac.first * (common_denominator / frac.second);
            }
    
            if(total_numerator == 0) return "0/1";
    
            int common_divisor = gcd(abs(total_numerator), common_denominator);
            int simplified_num = total_numerator / common_divisor;
            int simplified_den = common_denominator / common_divisor;
    
            return to_string(simplified_num) + "/" + to_string(simplified_den);
        }
    };