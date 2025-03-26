class Solution {
    public:
        // English: Returns the number of complete rows possible with n coins
        // عربي: يرجع عدد الصفوف الكاملة الممكنة باستخدام n عملات
        int arrangeCoins(int n) {
            // English: Using the quadratic formula: k(k+1)/2 <= n
            // English: k = (-1 + sqrt(1 + 8n)) / 2
            // عربي: باستخدام صيغة المعادلة التربيعية: k(k+1)/2 <= n
            // عربي: k = (-1 + جذر(1 + 8n)) / 2
            return (int)((-1 + sqrt(1 + 8.0 * n)) / 2);
        }
    };
    English Explanation:
    Problem Concept:
    We need to find how many complete rows we can build with n coins, where row i needs i coins.
    This forms an arithmetic sequence: 1 + 2 + 3 + ... + k ≤ n
    Mathematical Solution:
    Sum of first k numbers: k(k+1)/2 ≤ n
    Solve the quadratic equation: k² + k - 2n = 0
    Using quadratic formula, we get: k = (-1 + √(1 + 8n)) / 2
    Take the floor of this value to get complete rows
    Example (n = 5):
    k = (-1 + √(1 + 8*5)) / 2
    k = (-1 + √41) / 2 ≈ 2.702
    Floor(2.702) = 2
    Output: 2
    Time Complexity: O(1) - constant time
    Space Complexity: O(1) - constant space
    شرح بالعربية:
    مفهوم المشكلة:
    نحتاج لمعرفة كم عدد الصفوف الكاملة التي يمكن بناؤها بـ n عملات، حيث الصف i يحتاج i عملات.
    هذا يشكل متتالية حسابية: 1 + 2 + 3 + ... + k ≤ n
    الحل الرياضي:
    مجموع الأعداد الأولى k: k(k+1)/2 ≤ n
    حل المعادلة التربيعية: k² + k - 2n = 0
    باستخدام صيغة الحل، نحصل على: k = (-1 + √(1 + 8n)) / 2
    نأخذ الجزء الصحيح الأدنى لهذه القيمة للحصول على الصفوف الكاملة
    مثال (n = 5):
    k = (-1 + √(1 + 8*5)) / 2
    k = (-1 + √41) / 2 ≈ 2.702
    الجزء الصحيح الأدنى (2.702) = 2
    الإخراج: 2
    تعقيد الزمن: O(1) - زمن ثابت
    تعقيد المساحة: O(1) - مساحة ثابتة
    Alternative Solution (Binary Search) with English and Arabic comments:
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        // English: Returns the number of complete rows possible with n coins
        // عربي: يرجع عدد الصفوف الكاملة الممكنة باستخدام n عملات
        int arrangeCoins(int n) {
            long long left = 0, right = n;
            
            // English: Binary search to find largest k where k(k+1)/2 <= n
            // عربي: بحث ثنائي لإيجاد أكبر k حيث k(k+1)/2 <= n
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                long long coinsNeeded = mid * (mid + 1) / 2;
                
                if (coinsNeeded == n) {
                    return mid;
                } else if (coinsNeeded < n) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            // English: right is the last complete row
            // عربي: right هو آخر صف كامل
            return right;
        }
    };
    Both solutions:
    
    Handle the constraint 1 ≤ n ≤ 2³¹ - 1
    Return correct number of complete rows
    The mathematical solution is faster (O(1)), while binary search is O(log n)
    Use appropriate data types to avoid overflow (double in mathematical, long long in binary search)