class Solution {
public:
    string maskPII(string s) {
        if(isEmail(s)) return maskEmail(s);
        else return maskPhone(s);
    }

    bool isEmail(const string& s){
        return s.find('@') != string::npos;
    }

    string maskEmail(const string& s){
        string masked;
        int at_pos = s.find('@');

        masked += tolower(s[0]);
        masked += "*****";
        masked += tolower(s[at_pos - 1]);
        masked += '@';

        for(int i = at_pos + 1; i < s.size(); i++){
            masked += tolower(s[i]);
        }

        return masked;
    }

    string maskPhone(string s){
        string digits;
        for(char c : s){
            if(isdigit(c)){
                digits.push_back(c);
            }
        }

        int country_code_length = digits.size() - 10;
        string last_four = digits.substr(digits.size() - 4);

        if(country_code_length == 0) return "***-***-" + last_four;
        else{
            string country_code_stars(country_code_length, '*');
            return "+" + country_code_stars + "-***-***-" + last_four;
        }
    }

};