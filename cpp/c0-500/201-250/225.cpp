#include <queue>

class MyStack {
private:
    std::queue<int> q1;  // Main queue
    std::queue<int> q2;  // Temporary helper queue
    
public:
    MyStack() {
        // Constructor - queues are empty by default
    }
    
    void push(int x) {
        // Push new element to q2
        q2.push(x);
        
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap q1 and q2
        std::swap(q1, q2);
    }
    
    int pop() {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// Let's break down how this solution works:

// Approach:
// Use two queues: q1 (main) and q2 (temporary)
// For push: rearrange elements so newest is at front
// For pop/top: use queue's front (O(1))
// Maintain LIFO order by moving older elements behind new ones
// Operations:
// push(x):
// Add new element to q2
// Move all q1 elements to q2
// Swap q1 and q2
// Time Complexity: O(n)
// pop(): Remove and return front of q1 (O(1))
// top(): Return front of q1 (O(1))
// empty(): Check if q1 is empty (O(1))
// Example Walkthrough:
// text
// Wrap
// Copy
// ["MyStack", "push(1)", "push(2)", "top", "pop", "empty"]

// - push(1):
//   q1: [1]
//   q2: []

// - push(2):
//   q1: []
//   q2: [2]     // push 2 to q2
//   q2: [2,1]   // move 1 from q1 to q2
//   q1: [2,1]   // swap
//   q2: []

// - top(): returns 2
// - pop(): returns 2, q1 becomes [1]
// - empty(): returns false
// Time Complexity:
// push: O(n)
// pop: O(1)
// top: O(1)
// empty: O(1)
// Space Complexity: O(n) where n is number of elements
// Alternative Approach:

// We could make push O(1) and pop O(n) by simply pushing to back and rearranging during pop
// This solution prioritizes faster pop/top operations since they're typically more frequent
// Key Features:

// Uses only standard queue operations
// Maintains LIFO behavior
// Handles all constraints (1 ≤ x ≤ 9, ≤ 100 calls)
// Assumes valid pop/top calls as per problem statement
// The solution correctly implements a stack using queues and passes the example test case:

// push(1), push(2) → stack state: [2,1] (2 on top)
// top() → 2
// pop() → 2
// empty() → false
// This implementation is efficient for scenarios where pop and top are called more frequently than push, which is often the case with stack usage.