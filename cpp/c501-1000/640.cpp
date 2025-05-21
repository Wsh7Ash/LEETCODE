class Solution {
    public:
        pair<int, int> parse(string& expr){
            int a = 0;
            int b = 0;
            int sign = 1;
            int i = 0;
            int n = expr.size();
    
            while(i < n){
                if(expr[i] == '+' || expr[i] == '-'){
                    sign = (expr[i] == '+') ? 1 : -1;
                    i++;
                }else{
                    sign = 1;
                }
                int num = 0;
                bool has_num = false;
                bool is_x = false;
    
                while(i < n && isdigit(expr[i])){
                    num = num * 10 + (expr[i] - '0');
                    i++;
                    has_num = true;
                }
                if(i < n && expr[i] == 'x'){
                    is_x = true;
                    i++;
                }
                if(is_x){
                    if(has_num){
                        a += sign * num;
                    }else{
                        a += sign * 1;
                    }
                }else{
                    if(has_num){
                        b += sign * num;
                    }
                }
            }
            return {a,b};
        }
        string solveEquation(string equation) {
            size_t equal_pos = equation.find('=');
            string l = equation.substr(0, equal_pos);
            string r = equation.substr(equal_pos + 1);
            pair<int, int> l_eq = parse(l);
            pair<int, int> r_eq = parse(r);
            int a = l_eq.first - r_eq.first;
            int b = r_eq.second - l_eq.second;
    
            if(a == 0 && b == 0){
                return "Infinite solutions";
            }else if(a == 0){
                return "No solution";
            }else{
                return "x=" + to_string(b / a);
            }
        }
    };