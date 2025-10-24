class Solution {
    public:
        string findLexSmallestString(string s, int a, int b) {
            int n = s.length();
            string res = s;
            
            for (int rot = 0; rot < n; rot++) {
                string t = s;
                if (rot > 0) {
                    int shift = (rot * b) % n;
                    t = s.substr(n - shift) + s.substr(0, n - shift);
                }
                
                for (int odd_cnt = 0; odd_cnt < 10; odd_cnt++) {
                    string u = t;
                    for (int k = 1; k < n; k += 2) {
                        u[k] = '0' + (u[k] - '0' + odd_cnt * a) % 10;
                    }
                    
                    if (b % 2 == 1) {
                        for (int even_cnt = 0; even_cnt < 10; even_cnt++) {
                            string v = u;
                            for (int k = 0; k < n; k += 2) {
                                v[k] = '0' + (v[k] - '0' + even_cnt * a) % 10;
                            }
                            res = min(res, v);
                        }
                    } else {
                        res = min(res, u);
                    }
                }
            }
            
            return res;
        }
    };