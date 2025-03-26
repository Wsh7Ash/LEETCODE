class Solution {
    public:
        string toHex(int num) {
            if (num == 0) return "0";
            
            string hexChars = "0123456789abcdef";
            string result = "";
            unsigned int n = num;  // Handle negative numbers using unsigned int
            
            while (n > 0) {
                int digit = n & 0xF;        // Get last 4 bits
                result = hexChars[digit] + result;  // Prepend hex char
                n >>= 4;                    // Shift right by 4 bits
            }
            
            return result;
        }
    };
    How this solution works:
    
    Approach:
    Use bitwise operations to extract 4 bits at a time
    Convert each 4-bit group to hexadecimal character
    Build string from right to left
    Handle negative numbers using two's complement
    Key Components:
    hexChars: Mapping of 0-15 to hex digits
    unsigned int: Handles negative numbers correctly
    Bitwise AND (&) and right shift (>>=)
    Algorithm:
    Handle special case: return "0" if num is 0
    Convert to unsigned int to handle two's complement
    While number > 0:
    Extract last 4 bits using & 0xF
    Convert to hex char and prepend to result
    Shift right by 4 bits
    Return final string
    Example Walkthrough (num = 26):
    text
    
    Collapse
    
    Wrap
    
    Copy
    n = 26 (binary: 00011010)
    First iteration:
    - 26 & 15 = 10 (1010) → 'a'
    - n = 26 >> 4 = 1 (0001)
    Second iteration:
    - 1 & 15 = 1 (0001) → '1'
    - n = 1 >> 4 = 0
    Result: "1a"
    Negative Number (num = -1):
    text
    
    Collapse
    
    Wrap
    
    Copy
    n = 0xFFFFFFFF (32 ones)
    Processes 8 groups of 4 bits
    Each group is 1111 (15) → 'f'
    Result: "ffffffff"
    Complexity:
    Time: O(1) - fixed 32 bits to process
    Space: O(1) - output string is at most 8 chars
    Key Features:
    No leading zeros (except for "0" itself)
    Lowercase letters
    Handles negative numbers via twos complement
    No built-in conversion methods
    The solution satisfies all constraints:
    
    Works for -2³¹ to 2³¹-1
    Produces valid hexadecimal output
    Follows formatting requirements
    Alternative Bit-by-Bit Approach:
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        string toHex(int num) {
            if (num == 0) return "0";
            
            char hexChars[] = "0123456789abcdef";
            string result;
            unsigned int n = num;
            
            // Process all 32 bits, stop when no more non-zero digits
            for (int i = 7; i >= 0; i--) {
                int digit = (n >> (i * 4)) & 0xF;
                if (digit > 0 || !result.empty()) {
                    result += hexChars[digit];
                }
            }
            
            return result.empty() ? "0" : result;
        }
    };
    The first solution is preferred because:
    
    Simpler logic
    More efficient (stops when n becomes 0)
    Naturally builds string in correct order
    Both solutions correctly handle:
    
    Example 1: 26 → "1a"
    Example 2: -1 → "ffffffff"
    The solution uses bitwise operations to efficiently convert the number to hexadecimal while adhering to all specified requirements, including proper handling of negative numbers through twos complement representation.