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
    public:
        Node* intersect(Node* quadTree1, Node* quadTree2) {
            if(quadTree1->isLeaf){
                return quadTree1->val ? new Node(true, true) : quadTree2;
            }
    
            if(quadTree2->isLeaf){
                return quadTree2->val ? new Node(true, true) : quadTree1;
            }
    
            Node* topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
            Node* topRight = intersect(quadTree1->topRight, quadTree2->topRight);
            Node* bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            Node* bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
    
            if(topLeft->isLeaf && topRight->isLeaf &&
                bottomLeft->isLeaf && bottomRight->isLeaf &&
                topLeft->val == topRight->val && 
                topRight->val == bottomLeft->val &&
                bottomLeft->val == bottomRight->val){
                    bool val = topLeft->val;
                    delete topLeft;
                    delete topRight;
                    delete bottomLeft;
                    delete bottomRight;
                    return new Node(val, true);
                }
    
                return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    };