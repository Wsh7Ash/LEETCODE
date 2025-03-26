/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <stack>

class Solution {
public:
    // English: Add two numbers represented by linked lists and return sum as linked list
    // عربي: جمع عددين ممثلين بقوائم مرتبطة وإرجاع المجموع كقائمة مرتبطة
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // English: Use stacks to store digits in reverse order
        // عربي: استخدام مكدسات لتخزين الأرقام بترتيب عكسي
        stack<int> s1, s2;
        
        // English: Push all digits from l1 to stack s1
        // عربي: دفع جميع الأرقام من l1 إلى المكدس s1
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        // English: Push all digits from l2 to stack s2
        // عربي: دفع جميع الأرقام من l2 إلى المكدس s2
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* result = nullptr;
        int carry = 0;
        
        // English: Process digits from both stacks
        // عربي: معالجة الأرقام من كلا المكدسين
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            
            // English: Create new node with sum % 10
            // عربي: إنشاء عقدة جديدة بـ sum % 10
            ListNode* node = new ListNode(sum % 10);
            node->next = result;
            result = node;
            
            // English: Update carry for next iteration
            // عربي: تحديث الحمل للتكرار التالي
            carry = sum / 10;
        }
        
        return result;
    }
};
English Explanation:
Approach:
Since digits are in most-significant-first order, we need to process them from least significant digit
Use stacks to reverse the order of digits
Build result list from right to left while handling carry
Algorithm:
Push all digits from l1 and l2 into separate stacks
While either stack has digits or there's a carry:
Add digits from both stacks (if available) plus carry
Create new node with sum % 10
Update carry as sum / 10
Link new node to front of result
Return resulting list
Example: l1 = [7,2,4,3], l2 = [5,6,4]:
s1: [3,4,2,7], s2: [4,6,5]
3+4=7, carry=0: [7]
4+6=10, carry=1: [0,7]
2+5+1=8, carry=0: [8,0,7]
7+0=7, carry=0: [7,8,0,7]
Output: [7,8,0,7]
Complexity:
Time: O(n + m) where n, m are lengths of lists
Space: O(n + m) for stacks
شرح بالعربية:
النهج:
بما أن الأرقام بترتيب الأكثر أهمية أولاً، نحتاج لمعالجتها من الأقل أهمية
استخدام مكدسات لعكس ترتيب الأرقام
بناء القائمة الناتجة من اليمين إلى اليسار مع التعامل مع الحمل
الخوارزمية:
دفع جميع الأرقام من l1 و l2 إلى مكدسات منفصلة
طالما يوجد أرقام في أي مكدس أو يوجد حمل:
جمع الأرقام من كلا المكدسين (إذا كانت متاحة) بالإضافة إلى الحمل
إنشاء عقدة جديدة بـ sum % 10
تحديث الحمل بـ sum / 10
ربط العقدة الجديدة بمقدمة النتيجة
إرجاع القائمة الناتجة
مثال: l1 = [7,2,4,3], l2 = [5,6,4]:
s1: [3,4,2,7], s2: [4,6,5]
3+4=7، حمل=0: [7]
4+6=10، حمل=1: [0,7]
2+5+1=8، حمل=0: [8,0,7]
7+0=7، حمل=0: [7,8,0,7]
الإخراج: [7,8,0,7]
التعقيد:
الزمن: O(n + m) حيث n، m هما طولا القائمتين
المساحة: O(n + m) للمكدسات
The solution meets all requirements:

Correctly adds numbers with most significant digit first
Handles all test cases and constraints
Returns result as a linked list
Works with single-digit nodes (0-9)