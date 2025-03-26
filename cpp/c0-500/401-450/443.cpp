#include <vector>

class Solution {
public:
    // English: Compress the character array and return new length
    // عربي: ضغط مصفوفة الأحرف وإرجاع الطول الجديد
    int compress(vector<char>& chars) {
        // English: If array has length 1, no compression needed
        // عربي: إذا كان طول المصفوفة 1، لا حاجة للضغط
        if (chars.size() == 1) return 1;
        
        int write = 0;  // English: Write position in array
                        // عربي: موضع الكتابة في المصفوفة
        int count = 1;  // English: Count of consecutive characters
                        // عربي: عدد الأحرف المتتالية
        
        // English: Iterate through the array
        // عربي: التكرار عبر المصفوفة
        for (int i = 1; i < chars.size(); i++) {
            // English: If current char matches previous, increment count
            // عربي: إذا تطابق الحرف الحالي مع السابق، زيادة العدد
            if (chars[i] == chars[i-1]) {
                count++;
            } else {
                // English: Write the character
                // عربي: كتابة الحرف
                chars[write++] = chars[i-1];
                
                // English: If count > 1, write the count
                // عربي: إذا كان العدد > 1، كتابة العدد
                if (count > 1) {
                    string countStr = to_string(count);
                    for (char c : countStr) {
                        chars[write++] = c;
                    }
                }
                count = 1;  // English: Reset count for new group
                            // عربي: إعادة تعيين العدد للمجموعة الجديدة
            }
        }
        
        // English: Handle the last group
        // عربي: معالجة المجموعة الأخيرة
        chars[write++] = chars.back();
        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[write++] = c;
            }
        }
        
        return write;  // English: Return new length
                       // عربي: إرجاع الطول الجديد
    }
};
English Explanation:
Approach:
Use two-pointer technique: one for reading, one for writing
Count consecutive characters
Write character and count (if > 1) to the array in-place
Algorithm:
Track write position and count of consecutive chars
For each character:
If same as previous, increment count
If different, write previous char and count, reset count
Handle last group separately
Return final write position as new length
Example: ["a","a","b","b","c","c","c"]:
"aa": write "a2" (write=2)
"bb": write "b2" (write=4)
"ccc": write "c3" (write=6)
Output: 6, array becomes ["a","2","b","2","c","3"]
Complexity:
Time: O(n) where n is length of array
Space: O(1) auxiliary space (excluding small string for count)
شرح بالعربية:
النهج:
استخدام تقنية المؤشرين: واحد للقراءة وآخر للكتابة
عد الأحرف المتتالية
كتابة الحرف والعدد (إذا > 1) في المصفوفة مباشرة
الخوارزمية:
تتبع موضع الكتابة وعدد الأحرف المتتالية
لكل حرف:
إذا كان مثل السابق، زيادة العدد
إذا كان مختلفًا، كتابة الحرف السابق والعدد، إعادة تعيين العدد
معالجة المجموعة الأخيرة بشكل منفصل
إرجاع موضع الكتابة النهائي كطول جديد
مثال: ["a","a","b","b","c","c","c"]:
"aa": كتابة "a2" (write=2)
"bb": كتابة "b2" (write=4)
"ccc": كتابة "c3" (write=6)
الإخراج: 6، تصبح المصفوفة ["a","2","b","2","c","3"]
التعقيد:
الزمن: O(n) حيث n طول المصفوفة
المساحة: O(1) مساحة إضافية (باستثناء سلسلة صغيرة للعدد)
The solution meets all requirements:

Uses constant extra space
Modifies array in-place
Handles counts ≥ 10 correctly by splitting into multiple characters
Works within all constraints