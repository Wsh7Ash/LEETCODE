class Solution {
    public:
        vector<string> readBinaryWatch(int turnedOn) {
            vector<string> result;
            
            // Try all possible hour (0-11) and minute (0-59) combinations
            for (int h = 0; h < 12; h++) {
                for (int m = 0; m < 60; m++) {
                    // Count bits in hour and minute
                    int hourBits = countBits(h);
                    int minBits = countBits(m);
                    
                    // If total bits match turnedOn
                    if (hourBits + minBits == turnedOn) {
                        // Format time string: hour:minute with proper padding
                        string time = to_string(h) + ":";
                        if (m < 10) {
                            time += "0" + to_string(m);
                        } else {
                            time += to_string(m);
                        }
                        result.push_back(time);
                    }
                }
            }
            
            return result;
        }
        
    private:
        // Helper function to count number of 1 bits in a number
        int countBits(int num) {
            int count = 0;
            while (num > 0) {
                count += num & 1;
                num >>= 1;
            }
            return count;
        }
    };
    How this solution works:
    
    Approach:
    Brute force check all valid hours (0-11) and minutes (0-59)
    Count bits in each number
    If total bits match turnedOn, format and add to result
    Key Components:
    Hour range: 0-11 (4 LEDs)
    Minute range: 0-59 (6 LEDs)
    Bit counting helper function
    String formatting for output
    Algorithm:
    Nested loops for hours and minutes
    Check bit count matches turnedOn
    Format time string:
    No leading zero for hours
    Two digits for minutes (with leading zero if needed)
    Example Walkthrough (turnedOn = 1):
    text
    
    Collapse
    
    Wrap
    
    Copy
    h=0 (0 bits), m=1 (1 bit) → "0:01"
    h=0 (0 bits), m=2 (1 bit) → "0:02"
    h=0 (0 bits), m=4 (1 bit) → "0:04"
    h=0 (0 bits), m=8 (1 bit) → "0:08"
    h=0 (0 bits), m=16 (1 bit) → "0:16"
    h=0 (0 bits), m=32 (1 bit) → "0:32"
    h=1 (1 bit), m=0 (0 bits) → "1:00"
    h=2 (1 bit), m=0 (0 bits) → "2:00"
    h=4 (1 bit), m=0 (0 bits) → "4:00"
    h=8 (1 bit), m=0 (0 bits) → "8:00"
    Complexity:
    Time: O(12 * 60) = O(1) since ranges are fixed
    Space: O(1) for fixed output size (bounded by possible combinations)
    Key Features:
    Correct time format (no leading zero for hours, two-digit minutes)
    Handles all possible LED combinations
    Returns empty array when no valid times possible
    The solution satisfies all constraints:
    
    Works for turnedOn from 0 to 10
    Returns times in correct format
    Includes all possible valid combinations
    For optimization, we could:
    
    Pre-compute bit counts for 0-59
    Use bitset instead of countBits function But given the small fixed range (12 hours × 60 minutes), the simple brute force approach is efficient enough and very readable.
    The solution correctly handles:
    
    Example 1: turnedOn=1 returns 10 possible times
    Example 2: turnedOn=9 returns empty array (no valid time possible with 9 bits)
    Since we have only 4 LEDs for hours and 6 for minutes, maximum possible bits is 10, so any turnedOn > 10 will return empty array.