/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    public:
        Node* flatten(Node* head) {
            if (!head) return nullptr;
            
            Node* curr = head;
            
            while (curr) {
                if (!curr->child) {
                    // If no child, move to next node
                    curr = curr->next;
                } else {
                    // If there's a child, we need to merge it
                    Node* child = curr->child;
                    Node* next = curr->next;
                    
                    // Connect current node with child
                    curr->next = child;
                    child->prev = curr;
                    curr->child = nullptr;  // Set child pointer to null
                    
                    // Find the tail of the child list
                    Node* tail = child;
                    while (tail->next) {
                        tail = tail->next;
                    }
                    
                    // Connect tail with next node if it exists
                    if (next) {
                        tail->next = next;
                        next->prev = tail;
                    }
                    
                    // Move to next node
                    curr = curr->next;
                }
            }
            
            return head;
        }
    };
    Let's break down how this solution works:
    
    Approach:
    Iterate through the list node by node
    When we encounter a node with a child:
    Insert the child list between current node and next node
    Update all necessary pointers
    Set child pointer to null
    Continue until we process all nodes
    Algorithm Steps:
    If head is null, return nullptr
    Start with curr = head
    While curr exists:
    If no child: move to next node
    If child exists:
    Save child and next pointers
    Connect current with child
    Find tail of child list
    Connect tail with next (if exists)
    Move to next node
    Key Features:
    Maintains doubly linked list properties (prev/next pointers)
    Sets all child pointers to null as required
    Preserves original order while inserting child lists
    Handles empty lists and single nodes
    Example 1: [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
    At 3 (has child 7):
    Connect 3->7
    Find tail 10
    Connect 10->4
    At 8 (has child 11):
    Connect 8->11
    Find tail 12
    Connect 12->9
    Result: [1,2,3,7,8,11,12,9,10,4,5,6]
    Time and Space Complexity:
    Time Complexity: O(n) where n is total number of nodes
    Each node is processed exactly once
    Space Complexity: O(1)
    Only uses a constant amount of extra space
    Handling Constraints:
    Works for ≤ 1000 nodes
    Handles node values 1 ≤ val ≤ 10^5
    Works with empty lists
    The solution correctly flattens the multilevel list by:
    
    Inserting child lists between parent and next nodes
    Maintaining doubly linked list properties
    Setting all child pointers to null
    Preserving the order specified in the problem
    Returning the head of the flattened list