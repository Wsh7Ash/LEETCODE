// #include <iostream>
// #include <string>
// using namespace std;

// bool isNumber(string s) {
//     bool hasNum = false;   // To check if there is at least one digit
//     bool hasDot = false;   // To check if there is a decimal point
//     bool hasE = false;     // To check if there is an exponent ('e' or 'E')

//     int n = s.length();

//     for (int i = 0; i < n; i++) {
//         char c = s[i];

//         // Case 1: Digit (valid in any position)
//         if (isdigit(c)) {
//             hasNum = true;
//         }
//         // Case 2: Sign (+ or -) (valid only at the start or after 'e' or 'E')
//         else if (c == '+' || c == '-') {
//             if (i > 0 && (s[i - 1] != 'e' && s[i - 1] != 'E')) {
//                 return false; // Sign must be at the beginning or right after an exponent
//             }
//         }
//         // Case 3: Decimal point ('.')
//         else if (c == '.') {
//             if (hasDot || hasE) {
//                 return false; // A number can have only one '.' and it cannot appear after 'e'
//             }
//             hasDot = true;
//         }
//         // Case 4: Exponent ('e' or 'E')
//         else if (c == 'e' || c == 'E') {
//             if (hasE || !hasNum) {
//                 return false; // 'e' must appear only once and must come after a valid number
//             }
//             hasE = true;
//             hasNum = false; // Reset `hasNum` because exponent must be followed by a valid integer
//         }
//         // Case 5: Any other character is invalid
//         else {
//             return false;
//         }
//     }

//     return hasNum; // Ensure the string contains at least one digit
// }

// int main() {
//     cout << boolalpha; // Print 'true' or 'false' instead of 1 or 0

//     cout << isNumber("0") << endl;          // true
//     cout << isNumber("e") << endl;          // false
//     cout << isNumber(".") << endl;          // false
//     cout << isNumber("2e10") << endl;       // true
//     cout << isNumber("53.5e93") << endl;    // true
//     cout << isNumber("abc") << endl;        // false
//     cout << isNumber("1a") << endl;         // false
//     cout << isNumber("99e2.5") << endl;     // false
//     cout << isNumber("-+3") << endl;        // false
//     cout << isNumber("95a54e53") << endl;   // false

//     return 0;
// }

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        // Define the states of the DFA
        enum State {
            STATE_INITIAL,
            STATE_SIGN,
            STATE_INTEGER,
            STATE_POINT,
            STATE_POINT_WITHOUT_INTEGER,
            STATE_FRACTION,
            STATE_EXP,
            STATE_EXP_SIGN,
            STATE_EXP_INTEGER,
            STATE_END
        };

        // Define the input types
        enum InputType {
            INPUT_SIGN,
            INPUT_DIGIT,
            INPUT_POINT,
            INPUT_EXP,
            INPUT_INVALID
        };

        // Transition table for the DFA
        unordered_map<State, unordered_map<InputType, State>> transitionTable = {
            {STATE_INITIAL, {
                {INPUT_SIGN, STATE_SIGN},
                {INPUT_DIGIT, STATE_INTEGER},
                {INPUT_POINT, STATE_POINT_WITHOUT_INTEGER}
            }},
            {STATE_SIGN, {
                {INPUT_DIGIT, STATE_INTEGER},
                {INPUT_POINT, STATE_POINT_WITHOUT_INTEGER}
            }},
            {STATE_INTEGER, {
                {INPUT_DIGIT, STATE_INTEGER},
                {INPUT_POINT, STATE_POINT},
                {INPUT_EXP, STATE_EXP}
            }},
            {STATE_POINT, {
                {INPUT_DIGIT, STATE_FRACTION},
                {INPUT_EXP, STATE_EXP}
            }},
            {STATE_POINT_WITHOUT_INTEGER, {
                {INPUT_DIGIT, STATE_FRACTION}
            }},
            {STATE_FRACTION, {
                {INPUT_DIGIT, STATE_FRACTION},
                {INPUT_EXP, STATE_EXP}
            }},
            {STATE_EXP, {
                {INPUT_SIGN, STATE_EXP_SIGN},
                {INPUT_DIGIT, STATE_EXP_INTEGER}
            }},
            {STATE_EXP_SIGN, {
                {INPUT_DIGIT, STATE_EXP_INTEGER}
            }},
            {STATE_EXP_INTEGER, {
                {INPUT_DIGIT, STATE_EXP_INTEGER}
            }}
        };

        // Initial state
        State currentState = STATE_INITIAL;

        // Iterate through each character in the string
        for (char ch : s) {
            InputType inputType = getInputType(ch);
            if (inputType == INPUT_INVALID) {
                return false;
            }

            // Check if the current state has a transition for the input type
            if (transitionTable[currentState].find(inputType) == transitionTable[currentState].end()) {
                return false;
            }

            // Move to the next state
            currentState = transitionTable[currentState][inputType];
        }

        // Check if the final state is an accepting state
        return currentState == STATE_INTEGER || currentState == STATE_POINT || currentState == STATE_FRACTION || currentState == STATE_EXP_INTEGER;
    }

private:
    // Helper function to determine the input type
    InputType getInputType(char ch) {
        if (ch == '+' || ch == '-') {
            return INPUT_SIGN;
        } else if (isdigit(ch)) {
            return INPUT_DIGIT;
        } else if (ch == '.') {
            return INPUT_POINT;
        } else if (ch == 'e' || ch == 'E') {
            return INPUT_EXP;
        } else {
            return INPUT_INVALID;
        }
    }
};

int main() {
    Solution solution;
    cout << boolalpha; // Print bools as true/false instead of 1/0

    // Test cases
    cout << solution.isNumber("0") << endl; // true
    cout << solution.isNumber("e") << endl; // false
    cout << solution.isNumber(".") << endl; // false
    cout << solution.isNumber("2") << endl; // true
    cout << solution.isNumber("0089") << endl; // true
    cout << solution.isNumber("-0.1") << endl; // true
    cout << solution.isNumber("+3.14") << endl; // true
    cout << solution.isNumber("4.") << endl; // true
    cout << solution.isNumber("-.9") << endl; // true
    cout << solution.isNumber("2e10") << endl; // true
    cout << solution.isNumber("-90E3") << endl; // true
    cout << solution.isNumber("3e+7") << endl; // true
    cout << solution.isNumber("+6e-1") << endl; // true
    cout << solution.isNumber("53.5e93") << endl; // true
    cout << solution.isNumber("-123.456e789") << endl; // true
    cout << solution.isNumber("abc") << endl; // false
    cout << solution.isNumber("1a") << endl; // false
    cout << solution.isNumber("1e") << endl; // false
    cout << solution.isNumber("e3") << endl; // false
    cout << solution.isNumber("99e2.5") << endl; // false
    cout << solution.isNumber("--6") << endl; // false
    cout << solution.isNumber("-+3") << endl; // false
    cout << solution.isNumber("95a54e53") << endl; // false

    return 0;
}