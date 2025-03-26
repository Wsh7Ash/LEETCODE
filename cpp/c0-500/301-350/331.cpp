#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        // Initial capacity is 1 (for root)
        int capacity = 1;
        
        // Split the string by commas
        stringstream ss(preorder);
        string node;
        
        // Process each node
        while (getline(ss, node, ',')) {
            // Before processing current node, we need at least 1 capacity
            capacity--;
            if (capacity < 0) return false;
            
            // If it's not a null node, it takes 1 slot and adds 2 new slots
            if (node != "#") {
                capacity += 2;
            }
            // If it is "#", no new capacity is added (already subtracted 1)
        }
        
        // Valid if we used exactly all capacity
        return capacity == 0;
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    // Test case 1
    cout << boolalpha << solution.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") 
         << endl;  // true
    
    // Test case 2
    cout << solution.isValidSerialization("1,#") << endl;  // false
    
    // Test case 3
    cout << solution.isValidSerialization("9,#,#,1") << endl;  // false
    
    return 0;
}
How it works:

Capacity Concept:
Think of capacity as available slots for nodes
Start with 1 slot (for root)
Each non-null node:
Takes 1 slot (capacity - 1)
Creates 2 new slots (capacity + 2)
Each null node (#):
Takes 1 slot (capacity - 1)
Creates 0 new slots
Algorithm:
Process each node in preorder sequence
Before processing, subtract 1 from capacity
If capacity goes negative, invalid (too many nodes)
If non-null node, add 2 to capacity
At end, check if capacity is exactly 0
Example Walkthrough for "9,3,4,#,#,1,#,#,2,#,6,#,#":
capacity=1 → "9": 0+2=2
capacity=2 → "3": 1+2=3
capacity=3 → "4": 2+2=4
capacity=4 → "#": 3
capacity=3 → "#": 2
capacity=2 → "1": 1+2=3
capacity=3 → "#": 2
capacity=2 → "#": 1
capacity=1 → "2": 0+2=2
capacity=2 → "#": 1
capacity=1 → "6": 0+2=2
capacity=2 → "#": 1
capacity=1 → "#": 0
capacity=0: valid
Complexity:

Time Complexity: O(n) - single pass through the string
Space Complexity: O(1) - only using constant extra space
Key Features:

Doesn't reconstruct the tree
Handles comma-separated format
Works with integers and '#' nodes
Detects invalid sequences
The solution satisfies all constraints:

Works for string length 1 to 10^4
Handles integers 0-100 and '#' nodes
Assumes valid input format
For the examples:

"9,3,4,#,#,1,#,#,2,#,6,#,#" → true (valid tree)
"1,#" → false (incomplete tree)
"9,#,#,1" → false (extra node after complete tree)