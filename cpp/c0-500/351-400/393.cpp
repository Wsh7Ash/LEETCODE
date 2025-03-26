class Solution {
    public:
        bool validUtf8(vector<int>& data) {
            int bytesToProcess = 0;  // Number of continuation bytes remaining
            
            for (int i = 0; i < data.length(); i++) {
                if (bytesToProcess == 0) {
                    // New character - determine length from first byte
                    if ((data[i] >> 7) == 0) {
                        // 1-byte character: 0xxxxxxx
                        continue;
                    } else if ((data[i] >> 5) == 0b110) {
                        // 2-byte character: 110xxxxx
                        bytesToProcess = 1;
                    } else if ((data[i] >> 4) == 0b1110) {
                        // 3-byte character: 1110xxxx
                        bytesToProcess = 2;
                    } else if ((data[i] >> 3) == 0b11110) {
                        // 4-byte character: 11110xxx
                        bytesToProcess = 3;
                    } else {
                        // Invalid starting byte
                        return false;
                    }
                } else {
                    // Check continuation byte: must start with 10xxxxxx
                    if ((data[i] >> 6) != 0b10) {
                        return false;
                    }
                    bytesToProcess--;
                }
                
                // Check if we have enough bytes remaining
                if (bytesToProcess > 0 && i == data.length() - 1) {
                    return false;
                }
            }
            
            // Valid only if all bytes processed
            return bytesToProcess == 0;
        }
    };
    How this solution works:
    
    Key Logic:
    Track number of continuation bytes expected
    For each byte:
    If starting new character: check prefix and set bytesToProcess
    If continuation byte: verify 10xxxxxx pattern
    Use bit operations to check patterns
    Pattern Checking:
    1-byte: 0xxxxxxx → check if first bit is 0
    2-byte: 110xxxxx → check if first 3 bits are 110
    3-byte: 1110xxxx → check if first 4 bits are 1110
    4-byte: 11110xxx → check if first 5 bits are 11110
    Continuation: 10xxxxxx → check if first 2 bits are 10
    Implementation Details:
    >> shifts bits right to check prefixes
    Compare with binary patterns using 0b prefix
    bytesToProcess tracks remaining continuation bytes
    Early return on invalid patterns
    Example Walkthrough:
    text
    
    Collapse
    
    Wrap
    
    Copy
    Input: [197,130,1]
    197 (11000101):
    - >> 5 = 110 -> 2-byte char
    - bytesToProcess = 1
    130 (10000010):
    - >> 6 = 10 -> valid continuation
    - bytesToProcess = 0
    1 (00000001):
    - >> 7 = 0 -> 1-byte char
    Returns true
    Complexity:
    Time: O(n) where n is length of data
    Space: O(1) as we only use a single variable
    Edge Cases Handled:
    Incomplete multi-byte characters (end of array)
    Invalid starting patterns
    Invalid continuation bytes
    The solution satisfies all constraints:
    
    Works for array length 1 to 2*10^4
    Handles values 0 to 255 (8 bits)
    Correctly validates UTF-8 encoding rules
    For the example cases:
    
    [197,130,1] → true (valid 2-byte + 1-byte)
    [235,140,4] → false (invalid 3-byte sequence)
    The bit-shifting approach is efficient and directly checks the binary patterns required by UTF-8 specification, making it both accurate and performant.