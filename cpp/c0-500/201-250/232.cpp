To implement a queue using two stacks, we need to simulate the FIFO (First In First Out) behavior of a queue using the LIFO (Last In First Out) behavior of stacks. The key idea is to use one stack for pushing elements and another stack for popping and peeking elements.

Approach:
Two Stacks:

Use stack1 for pushing elements.

Use stack2 for popping and peeking elements.

Push Operation:

Simply push the element onto stack1.

Pop Operation:

If stack2 is empty, transfer all elements from stack1 to stack2. This reverses the order of elements, making the oldest element (front of the queue) the top of stack2.

Pop the top element from stack2.

Peek Operation:

Similar to the pop operation, if stack2 is empty, transfer all elements from stack1 to stack2.

Return the top element of stack2 without popping it.

Empty Operation:

The queue is empty if both stack1 and stack2 are empty.

Solution Code:
cpp
Copy
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> stack1; // Used for pushing elements
    stack<int> stack2; // Used for popping and peeking elements

public:
    MyQueue() {}

    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        if (stack2.empty()) {
            // Transfer all elements from stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    int peek() {
        if (stack2.empty()) {
            // Transfer all elements from stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};
Explanation:
Push Operation:

Elements are pushed onto stack1. This maintains the order of insertion.

Pop Operation:

If stack2 is empty, all elements from stack1 are transferred to stack2. This reverses the order, making the oldest element the top of stack2.

The top element of stack2 is popped and returned.

Peek Operation:

Similar to the pop operation, but the top element of stack2 is returned without popping it.

Empty Operation:

The queue is empty if both stack1 and stack2 are empty.

Example Walkthrough:
Input:
cpp
Copy
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek();  // return 1
myQueue.pop();   // return 1, queue is [2]
myQueue.empty(); // return false
Execution:
Push 1:

stack1: [1]

stack2: []

Push 2:

stack1: [1, 2]

stack2: []

Peek:

Transfer elements from stack1 to stack2:

stack1: []

stack2: [2, 1]

Return 1 (top of stack2).

Pop:

stack2 is not empty, so pop 1 from stack2.

stack1: []

stack2: [2]

Return 1.

Empty:

stack1 is empty, and stack2 is not empty.

Return false.

Key Points:
The solution uses two stacks to simulate a queue.

The pop and peek operations are optimized by transferring elements from stack1 to stack2 only when necessary.

The time complexity for push is 
O
(
1
)
O(1), and for pop and peek, it is amortized 
O
(
1
)
O(1) because each element is transferred from stack1 to stack2 at most once.

The space complexity is 
O
(
n
)
O(n), where 
n
n is the number of elements in the queue.