#include <vector>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;

        for (const string& token : tokens) {
            if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
                // If the token is a number (including negative numbers), push it onto the stack
                stack.push(stoi(token));
            } else {
                // If the token is an operator, pop the top two elements and apply the operator
                int operand2 = stack.top();
                stack.pop();
                int operand1 = stack.top();
                stack.pop();

                if (token == "+") {
                    stack.push(operand1 + operand2);
                } else if (token == "-") {
                    stack.push(operand1 - operand2);
                } else if (token == "*") {
                    stack.push(operand1 * operand2);
                } else if (token == "/") {
                    stack.push(operand1 / operand2);
                }
            }
        }

        return stack.top();
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "Result for Example 1: " << solution.evalRPN(tokens1) << endl; // Output: 9

    // Example 2
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "Result for Example 2: " << solution.evalRPN(tokens2) << endl; // Output: 6

    // Example 3
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "Result for Example 3: " << solution.evalRPN(tokens3) << endl; // Output: 22

    return 0;
}