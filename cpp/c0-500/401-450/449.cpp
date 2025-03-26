/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>
#include <sstream>

class Codec {
private:
    // English: Helper to serialize tree to string
    // عربي: مساعد لتسلسل الشجرة إلى سلسلة
    void serializeHelper(TreeNode* root, string& s) {
        if (!root) return;
        
        // English: Add current value followed by space
        // عربي: إضافة القيمة الحالية متبوعة بمسافة
        s += to_string(root->val) + " ";
        
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }
    
    // English: Helper to deserialize string to tree
    // عربي: مساعد لفك تسلسل السلسلة إلى شجرة
    TreeNode* deserializeHelper(stringstream& ss, int minVal, int maxVal) {
        string valStr;
        if (!(ss >> valStr)) return nullptr;
        
        int val = stoi(valStr);
        
        // English: Check if value is within BST bounds
        // عربي: التحقق مما إذا كانت القيمة ضمن حدود BST
        if (val <= minVal || val >= maxVal) {
            ss.seekg(-valStr.length() - 1, ios_base::cur);  // Rewind stream
            return nullptr;
        }
        
        // English: Create node and recursively build subtrees
        // عربي: إنشاء عقدة وبناء الأشجار الفرعية بشكل تكراري
        TreeNode* node = new TreeNode(val);
        node->left = deserializeHelper(ss, minVal, val);
        node->right = deserializeHelper(ss, val, maxVal);
        
        return node;
    }
    
public:
    // English: Serializes a BST to a string
    // عربي: تسلسل شجرة بحث ثنائية إلى سلسلة
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }

    // English: Deserializes a string to a BST
    // عربي: فك تسلسل سلسلة إلى شجرة بحث ثنائية
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        stringstream ss(data);
        return deserializeHelper(ss, INT_MIN, INT_MAX);
    }
};

/**
 * Your Codec object will be instantiated and called as such:
 * Codec* ser = new Codec();
 * Codec* deser = new Codec();
 * string tree = ser->serialize(root);
 * TreeNode* ans = deser->deserialize(tree);
 */
English Explanation:
Serialization:
Use preorder traversal (root, left, right)
Convert each value to string with space separator
BST property ensures unique reconstruction
Deserialization:
Use stringstream to process numbers
Maintain min/max bounds for BST property
Build tree recursively using preorder sequence
Example: [2,1,3]:
Serialize: "2 1 3 "
Deserialize:
2 (root)
1 (left, < 2)
3 (right, > 2)
Output: [2,1,3]
Complexity:
Time: O(n) for both serialize and deserialize
Space: O(n) for string, O(h) for recursion stack (h = height)
شرح بالعربية:
التسلسل:
استخدام الجولة المسبقة (الجذر، اليسار، اليمين)
تحويل كل قيمة إلى سلسلة مع فاصل مسافة
خاصية BST تضمن إعادة بناء فريدة
فك التسلسل:
استخدام stringstream لمعالجة الأرقام
الحفاظ على الحدود الدنيا/القصوى لخاصية BST
بناء الشجرة تكراريًا باستخدام تسلسل مسبق
مثال: [2,1,3]:
التسلسل: "2 1 3 "
فك التسلسل:
2 (الجذر)
1 (اليسار، < 2)
3 (اليمين، > 2)
الإخراج: [2,1,3]
التعقيد:
الزمن: O(n) لكل من التسلسل وفك التسلسل
المساحة: O(n) للسلسلة، O(h) لمكدس التكرار (h = الارتفاع)
Key Features:

Compact representation (just values with spaces)
Takes advantage of BST property for correct reconstruction
Handles all constraints:
0 to 10⁴ nodes
Values 0 to 10⁴
Valid BST input
No need for null markers due to BST properties