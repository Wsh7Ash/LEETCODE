/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
        // English: Find the minimum value in a BST (leftmost node)
        // عربي: إيجاد القيمة الدنيا في BST (العقدة الأقصى يسارًا)
        TreeNode* findMin(TreeNode* root) {
            while (root->left) {
                root = root->left;
            }
            return root;
        }
        
    public:
        // English: Delete node with given key from BST and return new root
        // عربي: حذف العقدة ذات المفتاح المعطى من BST وإرجاع الجذر الجديد
        TreeNode* deleteNode(TreeNode* root, int key) {
            // English: Base case: empty tree
            // عربي: الحالة الأساسية: شجرة فارغة
            if (!root) return nullptr;
            
            // English: Search for the node to delete
            // عربي: البحث عن العقدة للحذف
            if (key < root->val) {
                root->left = deleteNode(root->left, key);
            } else if (key > root->val) {
                root->right = deleteNode(root->right, key);
            } else {
                // English: Node found, handle deletion
                // عربي: تم العثور على العقدة، معالجة الحذف
                
                // English: Case 1: Leaf node
                // عربي: الحالة 1: عقدة ورقة
                if (!root->left && !root->right) {
                    delete root;
                    return nullptr;
                }
                
                // English: Case 2: Node with one child
                // عربي: الحالة 2: عقدة بطفل واحد
                if (!root->left) {
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                }
                if (!root->right) {
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }
                
                // English: Case 3: Node with two children
                // عربي: الحالة 3: عقدة بطفلين
                TreeNode* minNode = findMin(root->right);
                root->val = minNode->val;
                root->right = deleteNode(root->right, minNode->val);
            }
            
            return root;
        }
    };
    English Explanation:
    Approach:
    Recursively search for the node to delete
    Handle three cases: leaf node, one child, two children
    For two children, replace with minimum value from right subtree
    Algorithm:
    If key < root->val: recurse left
    If key > root->val: recurse right
    If key = root->val:
    No children: delete and return null
    One child: replace with child
    Two children: find min in right subtree, copy value, delete min
    Return updated root
    Example: [5,3,6,2,4,null,7], key=3:
    Find 3
    Has two children (2,4)
    Min in right (4) = 4
    Replace 3 with 4
    Delete old 4 (leaf)
    Output: [5,4,6,2,null,null,7]
    Complexity:
    Time: O(h) where h is height of tree
    Space: O(h) for recursion stack
    شرح بالعربية:
    النهج:
    البحث التكراري عن العقدة للحذف
    معالجة ثلاث حالات: عقدة ورقة، طفل واحد، طفلان
    لطفلين، استبدال بأدنى قيمة من الشجرة الفرعية اليمنى
    الخوارزمية:
    إذا key < root->val: التكرار يسارًا
    إذا key > root->val: التكرار يمينًا
    إذا key = root->val:
    لا أطفال: حذف وإرجاع null
    طفل واحد: استبدال بالطفل
    طفلان: إيجاد أدنى في اليمين، نسخ القيمة، حذف الأدنى
    إرجاع الجذر المحدث
    مثال: [5,3,6,2,4,null,7], key=3:
    إيجاد 3
    لها طفلان (2,4)
    أدنى في اليمين (4) = 4
    استبدال 3 بـ 4
    حذف 4 القديم (ورقة)
    الإخراج: [5,4,6,2,null,null,7]
    التعقيد:
    الزمن: O(h) حيث h هو ارتفاع الشجرة
    المساحة: O(h) لمكدس التكرار
    Key Features:
    
    Maintains BST properties
    Handles all deletion cases
    Works with all constraints:
    0 to 10⁴ nodes
    Values -10⁵ to 10⁵
    Unique values
    Valid BST input