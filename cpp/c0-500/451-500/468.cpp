#include <string>
#include <sstream>
using namespace std;

class Solution {
private:
    bool isValidIPv4(string ip) {
        // Count dots
        int dots = 0;
        for (char c : ip) {
            if (c == '.') dots++;
        }
        if (dots != 3) return false;
        
        stringstream ss(ip);
        string token;
        int count = 0;
        
        while (getline(ss, token, '.')) {
            count++;
            // Check each part
            if (token.empty() || token.length() > 3) return false;
            
            // Check for leading zeros
            if (token.length() > 1 && token[0] == '0') return false;
            
            // Check if all characters are digits
            for (char c : token) {
                if (!isdigit(c)) return false;
            }
            
            // Convert to number and check range
            int num = stoi(token);
            if (num < 0 || num > 255) return false;
        }
        
        // Should have exactly 4 parts
        return count == 4;
    }
    
    bool isValidIPv6(string ip) {
        // Count colons
        int colons = 0;
        for (char c : ip) {
            if (c == ':') colons++;
        }
        if (colons != 7) return false;
        
        stringstream ss(ip);
        string token;
        int count = 0;
        
        while (getline(ss, token, ':')) {
            count++;
            // Check length
            if (token.empty() || token.length() > 4) return false;
            
            // Check if all characters are valid hex digits
            for (char c : token) {
                if (!isxdigit(c)) return false;
            }
        }
        
        // Should have exactly 8 parts
        return count == 8;
    }
    
public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            return isValidIPv4(queryIP) ? "IPv4" : "Neither";
        }
        if (queryIP.find(':') != string::npos) {
            return isValidIPv6(queryIP) ? "IPv6" : "Neither";
        }
        return "Neither";
    }
};
Let's break down how this solution works:

Main Strategy:
First check if the string contains '.' (potential IPv4) or ':' (potential IPv6)
Then validate according to respective rules
Return appropriate string response
IPv4 Validation:
Must have exactly 3 dots (4 parts)
Each part must:
Not be empty and not exceed 3 characters
Have no leading zeros (unless single 0)
Contain only digits
Be in range 0-255
Use stringstream to split by dots
IPv6 Validation:
Must have exactly 7 colons (8 parts)
Each part must:
Not be empty and not exceed 4 characters
Contain only valid hexadecimal characters (0-9, a-f, A-F)
Leading zeros are allowed
Use stringstream to split by colons
Time and Space Complexity:
Time Complexity: O(n) where n is length of input string
Space Complexity: O(n) for stringstream and token storage
Example Walkthrough:
"172.16.254.1":
Contains dots → check IPv4
4 parts, no leading zeros, all digits, all ≤ 255
Returns "IPv4"
"2001:0db8:85a3:0:0:8A2E:0370:7334":
Contains colons → check IPv6
8 parts, all ≤ 4 chars, all valid hex
Returns "IPv6"
"256.256.256.256":
Contains dots → check IPv4
Numbers > 255
Returns "Neither"
Key Features:
Handles all edge cases (empty parts, leading zeros, invalid chars)
Uses isdigit() and isxdigit() for character validation
Properly validates numeric ranges
Meets all constraints