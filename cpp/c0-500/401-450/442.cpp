#include <vector>

class Solution {
public:
    // English: Find all numbers that appear twice in the array
    // عربي: إيجاد جميع الأرقام التي تظهر مرتين في المصفوفة
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        
        // English: Iterate through the array
        // عربي: التكرار عبر المصفوفة
        for (int i = 0; i < nums.size(); i++) {
            // English: Get the absolute value as index (since we may have marked it negative)
            // عربي: الحصول على القيمة المطلقة كفهرس (لأننا قد نكون قد وضعنا علامة سلبية)
            int index = abs(nums[i]) - 1;
            
            // English: If number at index is positive, mark it negative
            // English: If it's already negative, we found a duplicate
            // عربي: إذا كان الرقم في الفهرس موجبًا، نجعله سالبًا
            // عربي: إذا كان سالبًا بالفعل، فقد وجدنا مكررًا
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            } else {
                result.push_back(index + 1);
            }
        }
        
        return result;
    }
};
English Explanation:
Approach:
Use the array itself as a hash table
For each number n, mark the position (n-1) as negative
If we encounter a number whose corresponding position is already negative, it's a duplicate
Algorithm:
For each number in array:
Get its absolute value and use as index (minus 1 since range is 1 to n)
If number at that index is positive, mark it negative
If already negative, add to result as duplicate
Return duplicates found
Example: [4,3,2,7,8,2,3,1]:
4: mark index 3 (7 → -7)
3: mark index 2 (2 → -2)
2: mark index 1 (3 → -3)
7: mark index 6 (3 → -3)
8: mark index 7 (1 → -1)
2: index 1 already negative → add 2 to result
3: index 2 already negative → add 3 to result
1: mark index 0 (4 → -4)
Output: [2,3]
Complexity:
Time: O(n) - single pass through array
Space: O(1) auxiliary space (excluding output)
شرح بالعربية:
النهج:
استخدام المصفوفة نفسها كجدول تجزئة
لكل رقم n، وضع علامة على الموضع (n-1) كسالب
إذا واجهنا رقمًا وموضعه المقابل سالب بالفعل، فهو مكرر
الخوارزمية:
لكل رقم في المصفوفة:
أخذ قيمته المطلقة واستخدامه كفهرس (ناقص 1 لأن النطاق من 1 إلى n)
إذا كان الرقم في ذلك الفهرس موجبًا، اجعله سالبًا
إذا كان سالبًا بالفعل، أضفه إلى النتيجة كمكرر
إرجاع المكررات الموجودة
مثال: [4,3,2,7,8,2,3,1]:
4: وضع علامة على الفهرس 3 (7 → -7)
3: وضع علامة على الفهرس 2 (2 → -2)
2: وضع علامة على الفهرس 1 (3 → -3)
7: وضع علامة على الفهرس 6 (3 → -3)
8: وضع علامة على الفهرس 7 (1 → -1)
2: الفهرس 1 سالب بالفعل → إضافة 2 للنتيجة
3: الفهرس 2 سالب بالفعل → إضافة 3 للنتيجة
1: وضع علامة على الفهرس 0 (4 → -4)
الإخراج: [2,3]
التعقيد:
الزمن: O(n) - مرور واحد عبر المصفوفة
المساحة: O(1) مساحة إضافية (باستثناء الإخراج)
This solution meets all requirements:

O(n) time complexity
Constant extra space
Handles all constraints
Correctly identifies all duplicates