class Solution {
    public:
        int findNthDigit(int n) {
            // Use long to avoid overflow
            long digitCount = 1;  // Number of digits in current range
            long rangeCount = 9;  // Numbers in current range (9, 90, 900...)
            long start = 1;       // First number in current range
            
            // Step 1: Find the range containing nth digit
            while (n > digitCount * rangeCount) {
                n -= digitCount * rangeCount;  // Subtract digits in this range
                digitCount++;                  // Move to next digit length
                rangeCount *= 10;              // Next range has 10x numbers
                start *= 10;                   // Start of next range
            }
            
            // Step 2: Find the specific number
            long number = start + (n - 1) / digitCount;
            
            // Step 3: Find the digit position within the number
            int position = (n - 1) % digitCount;
            
            // Step 4: Extract the specific digit
            string numStr = to_string(number);
            return numStr[position] - '0';
        }
    };
    How this solution works:
    
    Key Insight:
    Numbers are grouped by digit length:
    1-9: 9 numbers, 9 digits
    10-99: 90 numbers, 180 digits
    100-999: 900 numbers, 2700 digits
    We can calculate which range contains our nth digit
    Algorithm Steps:
    Step 1: Determine the digit length range
    Step 2: Calculate the exact number containing nth digit
    Step 3: Find position within that number
    Step 4: Extract the digit
    Variables:
    digitCount: Length of numbers in current range
    rangeCount: How many numbers in current range
    start: First number in current range
    n: Adjusted to remaining digits after each range
    Example Walkthrough (n = 11):
    text
    
    Collapse
    
    Wrap
    
    Copy
    Initial: n=11, digitCount=1, rangeCount=9, start=1
    11 > 9*1 (9):
    - n = 11-9 = 2
    - digitCount = 2
    - rangeCount = 90
    - start = 10
    
    number = 10 + (2-1)/2 = 10
    position = (2-1)%2 = 1
    "10"[1] = '0'
    Result: 0
    Complexity:
    Time: O(log n) - number of digit ranges is logarithmic
    Space: O(1) - constant extra space (string is small)
    Key Features:
    Uses long to handle large n without overflow
    Handles all digit ranges efficiently
    Direct calculation instead of iteration
    The solution satisfies all constraints:
    
    Works for n from 1 to 2³¹-1
    Returns single digit as integer
    Alternative Approach (more intuitive but less efficient):
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        int findNthDigit(int n) {
            string sequence = "";
            int num = 1;
            while (sequence.length() < n) {
                sequence += to_string(num++);
            }
            return sequence[n-1] - '0';
        }
    };
    Time: O(n)
    Space: O(n)
    The optimized solution is much better because:
    
    Avoids generating full sequence
    Uses mathematical properties to jump to answer
    Constant space complexity
    Much faster for large n
    For the example cases:
    
    n=3: Returns 3 (from "123")
    n=11: Returns 0 (from "12345678910")
    The solution efficiently handles large inputs by working with ranges rather than individual numbers, making it suitable for the given constraint of n up to 2³¹-1.