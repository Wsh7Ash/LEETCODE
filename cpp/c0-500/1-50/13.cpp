int romanToInt(string s) {
        unordered_map<char, int> valueSymbols = { 
            {'I',1},
{'V',             5},
{'X',            10},
{'L',            50},
{'C',            100},
{'D' ,          500},
{'M',             1000}
        };

        int total = 0;
        int n = s.length();
        for(int i = 0; i < n;i++){
            if(i < n - 1 && valueSymbols[s[i]] < valueSymbols[s[i + 1]]){
                total -= valueSymbols[s[i]];
            }else{
                total += valueSymbols[s[i]];
            }
        }
        return total;
    }