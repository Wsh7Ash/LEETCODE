Problem Explanation:
We are given a binary tree and a target sum. We need to find the number of paths in the tree where the sum of the node values along the path equals the target sum. The path can start and end at any node, but it must go downwards (from parent to child nodes).

Example:
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8

Output: 3

Explanation: The paths that sum to 8 are:

5 -> 3

5 -> 2 -> 1

-3 -> 11

Approach:
Recursive Traversal: We will traverse the tree recursively.

Path Sum Calculation: For each node, we will calculate the sum of all paths that end at that node and check if any of them equals the target sum.

Prefix Sum: To optimize, we will use a hash map to store the prefix sums encountered so far. This will help us determine if a path with the target sum exists in constant time.

C++ Code with English and Arabic Comments:
cpp
Copy
#include <unordered_map>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        // Hash map to store the frequency of prefix sums
        // خريطة لتخزين تكرارات المجاميع الجزئية
        std::unordered_map<long, int> prefixSumCount;
        
        // Initialize the prefix sum count with 0:1 to handle the case where the path starts from the root
        // تهيئة خريطة المجاميع الجزئية بالقيمة 0:1 للتعامل مع الحالة التي يبدأ فيها المسار من الجذر
        prefixSumCount[0] = 1;
        
        // Start the recursive traversal
        // بدء التنقل التكراري
        return dfs(root, 0, targetSum, prefixSumCount);
    }
    
private:
    int dfs(TreeNode* node, long currentSum, int targetSum, std::unordered_map<long, int>& prefixSumCount) {
        if (!node) {
            return 0;
        }
        
        // Update the current sum by adding the current node's value
        // تحديث المجموع الحالي بإضافة قيمة العقدة الحالية
        currentSum += node->val;
        
        // Check if there is a prefix sum that, when subtracted from the current sum, equals the target sum
        // التحقق مما إذا كان هناك مجموع جزئي يمكن طرحه من المجموع الحالي ليعطي المجموع المطلوب
        int numPathsToCurr = prefixSumCount[currentSum - targetSum];
        
        // Update the prefix sum count with the current sum
        // تحديث خريطة المجاميع الجزئية بالمجموع الحالي
        prefixSumCount[currentSum]++;
        
        // Recursively traverse the left and right subtrees
        // التنقل التكراري في الجزء الأيسر والأيمن من الشجرة
        int res = numPathsToCurr + dfs(node->left, currentSum, targetSum, prefixSumCount) + dfs(node->right, currentSum, targetSum, prefixSumCount);
        
        // Backtrack: remove the current sum from the prefix sum count before returning to the parent node
        // التراجع: إزالة المجموع الحالي من خريطة المجاميع الجزئية قبل العودة إلى العقدة الأم
        prefixSumCount[currentSum]--;
        
        return res;
    }
};
Explanation:
Prefix Sum: We use a hash map to store the frequency of prefix sums encountered during the traversal. This helps us determine if a path with the target sum exists.

Recursive Traversal: We traverse the tree recursively, updating the current sum and checking if any path ending at the current node sums to the target.

Backtracking: After processing a node, we backtrack by removing the current sum from the prefix sum count to ensure that the count is accurate for other paths.

Complexity:
Time Complexity: O(N), where N is the number of nodes in the tree. We visit each node once.

Space Complexity: O(N), due to the recursion stack and the hash map storing prefix sums.

This approach efficiently solves the problem by leveraging the prefix sum technique and recursive tree traversal.