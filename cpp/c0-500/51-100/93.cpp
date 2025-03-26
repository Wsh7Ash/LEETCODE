class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            vector<string> result;
            if (s.size() < 4 || s.size() > 12) return result;  // Impossible to form valid IP with these lengths
            
            for (int i = 1; i < min(4, (int)s.size()); i++) {
                for (int j = i + 1; j < min(i + 4, (int)s.size()); j++) {
                    for (int k = j + 1; k < min(j + 4, (int)s.size()); k++) {
                        string part1 = s.substr(0, i);
                        string part2 = s.substr(i, j - i);
                        string part3 = s.substr(j, k - j);
                        string part4 = s.substr(k);
                        
                        // Check if all parts are valid
                        if (isValid(part1) && isValid(part2) && isValid(part3) && isValid(part4)) {
                            result.push_back(part1 + "." + part2 + "." + part3 + "." + part4);
                        }
                    }
                }
            }
            
            return result;
        }
        
        bool isValid(string part) {
            if (part.size() > 1 && part[0] == '0') return false;  // No leading zeros allowed
            int num = stoi(part);
            return num >= 0 && num <= 255;  // Must be within range [0, 255]
        }
    };
    