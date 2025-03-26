#include <stack>
#include <iostream>

using namespace std;

class MinStack {
private:
    stack<int> stack;
    stack<int> minStack;
    
public:
    MinStack() {}
    
    void push(int val) {
        stack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (stack.top() == minStack.top()) {
            minStack.pop();
        }
        stack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

// Driver Code
int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    cout << minStack.getMin() << endl; // Output: -3
    minStack.pop();
    
    cout << minStack.top() << endl;    // Output: 0
    cout << minStack.getMin() << endl; // Output: -2
    
    return 0;
}
