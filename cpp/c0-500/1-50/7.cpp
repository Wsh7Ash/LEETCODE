int reverse(int x) {
        

        long long reversedx = 0;
        while(x != 0){
            int digit = x % 10;
            reversedx = reversedx * 10 + digit;
            x /= 10;
        }
        if(reversedx < INT_MIN || reversedx > INT_MAX) return 0;
        
        return static_cast<int>(reversedx);
    }