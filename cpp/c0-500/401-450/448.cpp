#include <vector>

class Solution {
public:
    // English: Find all numbers missing from range [1,n] in the array
    // عربي: إيجاد جميع الأرقام المفقودة من النطاق [1,n] في المصفوفة
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // English: Mark presence of each number by making index (num-1) negative
        // عربي: وضع علامة على وجود كل رقم بجعل الفهرس (num-1) سالبًا
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        
        vector<int> result;
        
        // English: Any positive number's index + 1 is missing
        // عربي: أي رقم موجب يعني أن الفهرس + 1 مفقود
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};
English Explanation:
Approach:
Use the array itself as a hash table
Mark presence of number n by making index (n-1) negative
Positive numbers indicate missing values
Algorithm:
First pass: Mark presence of each number
For each num, make index (num-1) negative
Use abs() since numbers might already be marked
Second pass: Collect missing numbers
If nums[i] > 0, then (i+1) is missing
Example: [4,3,2,7,8,2,3,1]:
Mark: [-4,-3,-2,-7,8,-2,-3,-1]
Check: 8 at index 4 → 5 missing
Check: 8 at index 5 → 6 missing
Output: [5,6]
Complexity:
Time: O(n) - two passes through array
Space: O(1) - only output array as extra space
شرح بالعربية:
النهج:
استخدام المصفوفة نفسها كجدول تجزئة
وضع علامة على وجود الرقم n بجعل الفهرس (n-1) سالبًا
الأرقام الموجبة تشير إلى القيم المفقودة
الخوارزمية:
المرور الأول: وضع علامة على وجود كل رقم
لكل رقم، جعل الفهرس (num-1) سالبًا
استخدام abs() لأن الأرقام قد تكون مميزة بالفعل
المرور الثاني: جمع الأرقام المفقودة
إذا كان nums[i] > 0، فإن (i+1) مفقود
مثال: [4,3,2,7,8,2,3,1]:
وضع العلامات: [-4,-3,-2,-7,8,-2,-3,-1]
الفحص: 8 عند الفهرس 4 → 5 مفقود
الفحص: 8 عند الفهرس 5 → 6 مفقود
الإخراج: [5,6]
التعقيد:
الزمن: O(n) - مروران عبر المصفوفة
المساحة: O(1) - فقط مصفوفة الإخراج كمساحة إضافية
Key Features:

Meets O(n) time requirement
Uses constant extra space (excluding output)
Handles all constraints:
n from 1 to 10⁵
nums[i] in range [1,n]
Correctly identifies all missing numbers