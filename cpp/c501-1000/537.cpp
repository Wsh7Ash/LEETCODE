class Solution {
    public:
        void parseComplex(string& num, int& real, int& imag){
            size_t plus_pos = num.find('+');
            real = stoi(num.substr(0, plus_pos));
            imag = stoi(num.substr(plus_pos + 1, num.size() - plus_pos - 2));
        }
        string complexNumberMultiply(string num1, string num2) {
            int ar, ai, br, bi;
            parseComplex(num1, ar, ai);
            parseComplex(num2, br, bi);
    
            int real_part = ar * br - ai * bi;
            int imag_part = ar * bi + ai * br;
    
            return to_string(real_part) + "+" + to_string(imag_part) + "i";
        }
    };