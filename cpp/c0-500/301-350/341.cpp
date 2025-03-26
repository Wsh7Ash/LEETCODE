/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include <vector>
#include <stack>
using namespace std;

class NestedIterator {
private:
    stack<NestedInteger> stk;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Push all elements in reverse order to process from start
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            stk.push(nestedList[i]);
        }
    }
    
    int next() {
        // Assume hasNext() was called and returned true
        int result = stk.top().getInteger();
        stk.pop();
        return result;
    }
    
    bool hasNext() {
        while (!stk.empty()) {
            NestedInteger curr = stk.top();
            
            if (curr.isInteger()) {
                return true;  // Found next integer
            }
            
            // If it's a list, pop it and push its elements
            stk.pop();
            vector<NestedInteger> nestedList = curr.getList();
            for (int i = nestedList.size() - 1; i >= 0; i--) {
                stk.push(nestedList[i]);
            }
        }
        return false;  // No more integers found
    }
};

// Test code (simplified simulation)
#include <iostream>
struct NestedInteger {
    bool isInt;
    int value;
    vector<NestedInteger> list;
    
    NestedInteger(int val) : isInt(true), value(val) {}
    NestedInteger(vector<NestedInteger> l) : isInt(false), list(l) {}
    
    bool isInteger() const { return isInt; }
    int getInteger() const { return value; }
    const vector<NestedInteger>& getList() const { return list; }
};

int main() {
    // Test case 1: [[1,1],2,[1,1]]
    vector<NestedInteger> list1 = {
        NestedInteger({NestedInteger(1), NestedInteger(1)}),
        NestedInteger(2),
        NestedInteger({NestedInteger(1), NestedInteger(1)})
    };
    NestedIterator iter1(list1);
    vector<int> result1;
    while (iter1.hasNext()) {
        result1.push_back(iter1.next());
    }
    for (int num : result1) cout << num << " ";  // 1 1 2 1 1
    cout << endl;
    
    // Test case 2: [1,[4,[6]]]
    vector<NestedInteger> list2 = {
        NestedInteger(1),
        NestedInteger({NestedInteger(4), NestedInteger({NestedInteger(6)})})
    };
    NestedIterator iter2(list2);
    vector<int> result2;
    while (iter2.hasNext()) {
        result2.push_back(iter2.next());
    }
    for (int num : result2) cout << num << " ";  // 1 4 6
    cout << endl;
    
    return 0;
}
How it works:

Stack-Based Approach:
Use a stack to store NestedInteger objects
Process elements in order by pushing them in reverse initially
Constructor:
Pushes all top-level elements onto stack in reverse order
Ensures left-to-right processing
hasNext():
While stack is not empty:
If top is integer, return true
If top is list, pop it and push its elements in reverse order
Return false if no integers remain
next():
Returns top integer and removes it from stack
Assumes hasNext() was called first
Example Walkthrough for [[1,1],2,[1,1]]:
Init: stack = [[1,1], 2, [1,1]] (top to bottom)
hasNext(): pops [1,1], pushes 1,1 → stack = [1, 1, 2, [1,1]]
next(): returns 1, stack = [1, 2, [1,1]]
hasNext(): true, stack = [1, 2, [1,1]]
next(): returns 1, stack = [2, [1,1]]
Continues until all processed: 1,1,2,1,1
Complexity:

Time Complexity:
Constructor: O(n) where n is number of top-level elements
hasNext(): O(1) amortized
next(): O(1)
Space Complexity: O(N) where N is total number of nested elements
The solution satisfies all constraints:

Works for nested list length 1 to 500
Handles integers from -10^6 to 10^6
Correctly flattens nested structure
For the examples:

[[1,1],2,[1,1]] → [1,1,2,1,1]
[1,[4,[6]]] → [1,4,6]
This solution efficiently flattens the nested list by:

Using lazy evaluation (only flattens as needed)
Maintaining order with stack
Handling arbitrary nesting levels
Meeting iterator interface requirements