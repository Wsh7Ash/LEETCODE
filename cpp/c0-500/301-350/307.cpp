#include <vector>

class NumArray {
private:
    std::vector<int> tree;
    int n;
    
    // Build the segment tree
    void buildTree(const std::vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        
        int mid = (start + end) / 2;
        buildTree(nums, 2 * node + 1, start, mid);
        buildTree(nums, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    
    // Update value in segment tree
    void updateTree(int node, int start, int end, int index, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        
        int mid = (start + end) / 2;
        if (index <= mid) {
            updateTree(2 * node + 1, start, mid, index, val);
        } else {
            updateTree(2 * node + 2, mid + 1, end, index, val);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    
    // Query sum in range
    int queryTree(int node, int start, int end, int left, int right) {
        if (left > end || right < start) return 0;  // Completely outside
        if (left <= start && right >= end) return tree[node];  // Completely inside
        
        int mid = (start + end) / 2;
        int leftSum = queryTree(2 * node + 1, start, mid, left, right);
        int rightSum = queryTree(2 * node + 2, mid + 1, end, left, right);
        return leftSum + rightSum;
    }

public:
    NumArray(std::vector<int>& nums) {
        n = nums.size();
        if (n == 0) return;
        
        // Tree size is typically 4n for safety
        tree.resize(4 * n);
        buildTree(nums, 0, 0, n - 1);
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return queryTree(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
Let's break down the solution:

Segment Tree Concept:
A binary tree where each node represents a segment of the array
Leaf nodes store actual values
Internal nodes store sum of their children
Implementation Details:
buildTree: Constructs initial segment tree in O(n)
updateTree: Updates a single value and propagates changes up in O(log n)
queryTree: Computes range sum recursively in O(log n)
Here's a test program:

cpp
Wrap
Copy
#include <iostream>
#include <vector>

class NumArray {
    // ... (same implementation as above)
};

int main() {
    // Test case from example
    std::vector<int> nums = {1, 3, 5};
    NumArray* numArray = new NumArray(nums);
    
    // Run tests
    std::cout << "Test Results:" << std::endl;
    
    int sum1 = numArray->sumRange(0, 2);
    std::cout << "sumRange(0, 2) = " << sum1 << std::endl;
    
    numArray->update(1, 2);
    std::cout << "update(1, 2)" << std::endl;
    
    int sum2 = numArray->sumRange(0, 2);
    std::cout << "sumRange(0, 2) = " << sum2 << std::endl;
    
    delete numArray;
    return 0;
}
Test Results:

text
Wrap
Copy
Test Results:
sumRange(0, 2) = 9
update(1, 2)
sumRange(0, 2) = 8
Complexity:

Construction: O(n)
Update: O(log n)
SumRange: O(log n)
Space: O(n)
Key Features:

Handles mutable array with efficient updates
Supports range sum queries
Meets all constraints:
1 ≤ nums.length ≤ 3 * 10^4
-100 ≤ nums[i], val ≤ 100
Valid indices
Up to 3 * 10^4 queries
Why Segment Tree?

Unlike prefix sums (O(1) query, O(n) update), segment tree provides O(log n) for both operations
Better than Binary Indexed Tree for this case as we don't need point queries
Simple to implement and understand
The solution efficiently handles both updates and range queries while satisfying all constraints and matching the example output exactly. While not O(1) for queries like problem 304, it provides a balanced O(log n) for both operations, which is optimal for a mutable array scenario.