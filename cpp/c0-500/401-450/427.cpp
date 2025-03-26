/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    private:
        // Helper function to check if all values in a subgrid are same
        bool isLeafNode(vector<vector<int>>& grid, int x, int y, int n) {
            int val = grid[x][y];
            for (int i = x; i < x + n; i++) {
                for (int j = y; j < y + n; j++) {
                    if (grid[i][j] != val) {
                        return false;
                    }
                }
            }
            return true;
        }
        
        // Recursive function to construct quad tree
        Node* constructHelper(vector<vector<int>>& grid, int x, int y, int n) {
            // Base case: if all values are same, create leaf node
            if (isLeafNode(grid, x, y, n)) {
                return new Node(grid[x][y] == 1, true);
            }
            
            // If not all values are same, divide into 4 quadrants
            n = n / 2;
            Node* topLeft = constructHelper(grid, x, y, n);
            Node* topRight = constructHelper(grid, x, y + n, n);
            Node* bottomLeft = constructHelper(grid, x + n, y, n);
            Node* bottomRight = constructHelper(grid, x + n, y + n, n);
            
            // Create internal node with four children
            return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
        }
        
    public:
        Node* construct(vector<vector<int>>& grid) {
            return constructHelper(grid, 0, 0, grid.size());
        }
    };
    Let's break down how this solution works:
    
    Key Components:
    isLeafNode: Helper function that checks if all values in a subgrid are the same
    constructHelper: Recursive function that builds the quad tree
    Main construct function that starts the recursion
    Algorithm:
    For each subgrid:
    Check if all values are same (can be a leaf)
    If yes, create leaf node with appropriate value
    If no, divide into 4 equal quadrants and recurse
    Create internal node linking the 4 child nodes
    Implementation Details:
    Parameters (x, y) represent top-left corner of current subgrid
    n represents size of current subgrid
    Grid is divided by halving n for each recursive call
    Leaf nodes have isLeaf=true and val set to grid value
    Internal nodes have isLeaf=false and four children
    Example 1: [[0,1],[1,0]]
    Grid not uniform → divide into 4
    Each 1×1 quadrant becomes leaf node
    Result: root node with 4 leaf children
    Time and Space Complexity:
    Time Complexity: O(n²log n) where n is grid size
    At each level, we check all elements in subgrid
    Tree height is log n (halving at each step)
    Space Complexity: O(log n) for recursion stack
    Plus O(n²) for storing the tree nodes
    Handling Constraints:
    Works for n = 2^x where 0 ≤ x ≤ 6
    Handles grids of 0's and 1's only
    Produces valid quad tree representation
    The solution follows the quad tree construction rules:
    
    Leaf nodes for uniform regions
    Internal nodes with 4 children for mixed regions
    Correct val and isLeaf settings
    Proper recursive division of the grid