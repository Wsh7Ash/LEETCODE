To solve the problem of removing duplicate letters while ensuring the result is the smallest in lexicographical order, we can use a greedy approach with a stack. The idea is to process the string character by character and maintain a stack to build the result. We also use additional data structures to keep track of the frequency of each character and whether a character has already been included in the result.

Steps:
Count Frequencies: First, count the frequency of each character in the string.

Use a Stack: Iterate through the string and use a stack to build the result.

Greedy Selection: For each character, while the stack is not empty, the current character is smaller than the top of the stack, and the top character will appear again later, pop the top character from the stack.

Mark Visited: Once a character is added to the stack, mark it as visited to avoid duplicates.

Build Result: After processing all characters, the stack will contain the result in the correct order.

Code Implementation:
cpp
Copy
#include <string>
#include <vector>
#include <stack>

class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        // Count the frequency of each character
        std::vector<int> frequency(26, 0);
        for (char c : s) {
            frequency[c - 'a']++;
        }

        // Track whether a character is already in the result
        std::vector<bool> inStack(26, false);

        // Stack to build the result
        std::stack<char> stack;

        for (char c : s) {
            // Decrease the frequency of the current character
            frequency[c - 'a']--;

            // If the character is already in the stack, skip it
            if (inStack[c - 'a']) {
                continue;
            }

            // While the stack is not empty, the current character is smaller than the top of the stack,
            // and the top character will appear again later, pop the top character
            while (!stack.empty() && c < stack.top() && frequency[stack.top() - 'a'] > 0) {
                inStack[stack.top() - 'a'] = false;
                stack.pop();
            }

            // Push the current character to the stack and mark it as in the stack
            stack.push(c);
            inStack[c - 'a'] = true;
        }

        // Build the result string from the stack
        std::string result;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }

        // Reverse the result to get the correct order
        std::reverse(result.begin(), result.end());
        return result;
    }
};
Explanation:
Frequency Count: We count how many times each character appears in the string.

Stack Usage: We use a stack to build the result. The stack ensures that we can easily remove characters if a smaller character comes later.

Greedy Logic: For each character, we check if it can replace a larger character in the stack (while ensuring the larger character will appear again later).

Visited Tracking: We use a boolean array to track whether a character is already in the stack to avoid duplicates.

Result Construction: After processing all characters, the stack contains the result in reverse order, so we reverse it to get the final string.

Example Walkthrough:
Input: s = "cbacdcbc"
Frequency count: {'a': 1, 'b': 2, 'c': 3, 'd': 1}

Stack operations:

Push 'c', stack = ['c']

Push 'b', stack = ['c', 'b']

Push 'a', stack = ['a'] (pop 'b' and 'c' because 'a' is smaller and 'b' and 'c' will appear later)

Push 'c', stack = ['a', 'c']

Push 'd', stack = ['a', 'c', 'd']

Push 'c', stack = ['a', 'c', 'd'] (skip, already in stack)

Push 'b', stack = ['a', 'c', 'd', 'b']

Push 'c', stack = ['a', 'c', 'd', 'b'] (skip, already in stack)

Result: "acdb"

Time Complexity:
O(n): We process each character in the string once, and each character is pushed and popped from the stack at most once.

Space Complexity:
O(1): The stack and auxiliary arrays use constant space (since the alphabet size is fixed at 26).