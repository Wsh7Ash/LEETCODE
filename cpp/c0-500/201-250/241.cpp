// Let's solve this problem using a divide-and-conquer approach with recursion in C++. The idea is to split the expression at each operator and recursively compute all possible results for the left and right parts, then combine them based on the operator.

// Here's the solution:

// cpp
// Wrap
// Copy
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> diffWaysToCompute(std::string expression) {
        std::vector<int> results;
        
        // Iterate through the expression to find operators
        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                // Split the expression into left and right parts
                std::string left = expression.substr(0, i);
                std::string right = expression.substr(i + 1);
                
                // Recursively compute results for left and right parts
                std::vector<int> leftResults = diffWaysToCompute(left);
                std::vector<int> rightResults = diffWaysToCompute(right);
                
                // Combine results based on the operator
                for (int l : leftResults) {
                    for (int r : rightResults) {
                        if (c == '+') {
                            results.push_back(l + r);
                        } else if (c == '-') {
                            results.push_back(l - r);
                        } else if (c == '*') {
                            results.push_back(l * r);
                        }
                    }
                }
            }
        }
        
        // Base case: if no operators found, it's a number
        if (results.empty()) {
            results.push_back(std::stoi(expression));
        }
        
        return results;
    }
};
// Let's break down how this solution works:

// Recursive Approach:
// For each character in the expression, we check if it's an operator (+, -, *)
// When we find an operator, we split the expression into two parts: left and right
// We recursively compute all possible results for both parts
// Base Case:
// If no operators are found (results remains empty), it means we've reached a pure number
// We convert this number string to integer using stoi() and return it as a single-element vector
// Combining Results:
// For each operator found, we:
// Get all possible results from left part
// Get all possible results from right part
// Combine each left result with each right result using the operator
// Add all combinations to our results vector
// Time Complexity: O(C(n)), where C(n) is the nth Catalan number
// This is because we're generating all possible ways to parenthesize the expression
// For n operators, there are C(n) valid ways to add parentheses
// Space Complexity: O(C(n)) to store all possible results
// Example walkthrough for "2*3-4":

// First split at '*': "2" and "3-4"
// "2" returns [2]
// "3-4" splits at '-': "3" and "4"
// "3" returns [3]
// "4" returns [4]
// 3-4 returns [3-4] = [-1]
// 2*[3-4] returns [2*-1] = [-2]
// Second split at '-': "2*3" and "4"
// "23" splits at '': "2" and "3"
// "2" returns [2]
// "3" returns [3]
// 2*3 returns [6]
// "4" returns [4]
// [6]-4 returns [2]
// Final result: [-2, 2]
// The solution handles all the constraints:

// Works for expression length 1 to 20
// Handles operators +, -, *
// Works with numbers 0-99
// Results fit in 32-bit integer
// Returns all possible combinations in any order