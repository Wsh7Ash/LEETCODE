int myAtoi(string s) {
       int n = s.length();
       int i = 0;
       int sign = 1;
       int res = 0;

       while(i < n && s[i] == ' ') {
        i++;
       } 
       if( i < n && (s[i] == '+' || s[i] =='-')){
        sign = (s[i] == '-') ? -1 : 1;
        i++;
       }
       while(i < n && isdigit(s[i])){
        int digit = s[i] - '0';
        if(res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10)){
            return(sign == 1)? INT_MAX : INT_MIN;
        } 
        res = res * 10 + digit;
        i++;
       }
       return res * sign;
    }