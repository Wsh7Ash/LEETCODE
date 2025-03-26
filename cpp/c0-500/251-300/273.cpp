class Solution {
    private:
        // Arrays for word representations
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", 
                               "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    
        // Helper function to convert numbers less than 1000
        string numberToWordsLessThanThousand(int num) {
            if (num == 0) return "";
            
            string result;
            
            // Handle hundreds
            if (num >= 100) {
                result += ones[num / 100] + " Hundred";
                num %= 100;
                if (num > 0) result += " ";
            }
            
            // Handle tens and ones
            if (num >= 20) {
                result += tens[num / 10];
                num %= 10;
                if (num > 0) result += " " + ones[num];
            }
            else if (num >= 10) {
                result += teens[num - 10];
            }
            else if (num > 0) {
                result += ones[num];
            }
            
            return result;
        }
    
    public:
        string numberToWords(int num) {
            if (num == 0) return "Zero";
            
            string result;
            int thousandIndex = 0;
            
            // Process number in groups of 1000
            while (num > 0) {
                if (num % 1000 > 0) {
                    string part = numberToWordsLessThanThousand(num % 1000);
                    if (thousandIndex > 0) {
                        part += " " + thousands[thousandIndex];
                    }
                    if (!result.empty()) {
                        result = part + " " + result;
                    } else {
                        result = part;
                    }
                }
                num /= 1000;
                thousandIndex++;
            }
            
            return result;
        }
    };
    How it works:
    
    Data Structures:
    Arrays for ones (1-9), teens (10-19), tens (20-90), and thousands scale
    Helper Function (numberToWordsLessThanThousand):
    Handles numbers 1-999
    Breaks into hundreds, tens, and ones
    Special cases for teens (10-19)
    Adds appropriate spacing
    Main Function:
    Handles zero case separately
    Processes number in groups of 1000 (ones, thousands, millions, billions)
    Uses helper function for each group
    Adds scale words (Thousand, Million, Billion) as needed
    Builds result string from right to left
    Time Complexity: O(1) - Since the input is bounded by 2³¹-1, we process a constant maximum number of digits
    Space Complexity: O(1) - Fixed size arrays and string construction
    
    Examples:
    
    num = 123:
    123 % 1000 = 123
    "One Hundred Twenty Three"
    num = 12345:
    345: "Three Hundred Forty Five"
    12: "Twelve Thousand"
    Result: "Twelve Thousand Three Hundred Forty Five"
    num = 1234567:
    567: "Five Hundred Sixty Seven"
    234: "Two Hundred Thirty Four Thousand"
    1: "One Million"
    Result: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
    The solution handles all constraints (0 ≤ num ≤ 2³¹-1) and produces properly formatted English words with:
    
    Correct capitalization (first letter of words)
    Proper spacing
    Correct handling of all number ranges
    No leading/trailing spaces