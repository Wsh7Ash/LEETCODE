#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0"; // Edge case: numerator is 0

        string result;

        // Handle negative results
        if ((numerator < 0) ^ (denominator < 0)) {
            result += '-';
        }

        // Work with absolute values
        long num = abs((long)numerator);
        long den = abs((long)denominator);

        // Integer part
        result += to_string(num / den);
        num %= den;
        if (num == 0) return result; // No fractional part

        // Fractional part
        result += '.';
        unordered_map<long, int> remainderMap; // Maps remainder to its position in the result
        while (num != 0) {
            if (remainderMap.find(num) != remainderMap.end()) {
                // Insert parentheses around the repeating part
                result.insert(remainderMap[num], "(");
                result += ')';
                break;
            }
            remainderMap[num] = result.size(); // Store the position of the current remainder
            num *= 10;
            result += to_string(num / den);
            num %= den;
        }

        return result;
    }
};