#include <vector>
#include <unordered_map>

class Solution {
public:
    // English: Find number of arithmetic subsequences in array
    // عربي: إيجاد عدد التتابعات الحسابية في المصفوفة
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        
        // English: dp[i][diff] stores count of subsequences ending at i with given difference
        // عربي: dp[i][diff] يخزن عدد التتابعات المنتهية عند i بالفرق المعطى
        vector<unordered_map<long long, int>> dp(n);
        
        // English: Iterate through all pairs
        // عربي: التكرار عبر كل الأزواج
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // English: Calculate difference (using long long to avoid overflow)
                // عربي: حساب الفرق (باستخدام long long لتجنب التجاوز)
                long long diff = (long long)nums[i] - nums[j];
                
                // English: Add count of sequences ending at j with this difference
                // عربي: إضافة عدد التتابعات المنتهية عند j بهذا الفرق
                int count = dp[j].count(diff) ? dp[j][diff] : 0;
                
                // English: Update count for sequences ending at i
                // عربي: تحديث العدد للتتابعات المنتهية عند i
                dp[i][diff] += count + 1;
                
                // English: Add to result only sequences of length 3 or more
                // عربي: إضافة إلى النتيجة فقط التتابعات بطول 3 أو أكثر
                result += count;
            }
        }
        
        return result;
    }
};
English Explanation:
Approach:
Use dynamic programming with a hash map at each index
For each position, store counts of subsequences ending there with various differences
Count only sequences of length 3 or more
Algorithm:
dp[i][diff]: number of subsequences ending at i with difference diff
For each pair (j,i):
Calculate difference
Get count of sequences ending at j with same difference
Update count at i (adding 1 for the pair itself)
Add to result the count of sequences extended to length 3+
Example: [2,4,6,8,10]:
[2,4]: diff=2, dp[1][2]=1
[2,6]: diff=4, dp[2][4]=1
[4,6]: diff=2, dp[2][2]=1
[2,4,6]: diff=2, dp[2][2]=2, result+=1
Continue for all pairs...
Final result: 7
Complexity:
Time: O(n²) - checking all pairs
Space: O(n²) - storing differences at each position
شرح بالعربية:
النهج:
استخدام البرمجة الديناميكية مع جدول تجزئة عند كل فهرس
لكل موضع، تخزين عدد التتابعات المنتهية هناك بفروق مختلفة
عد فقط التتابعات بطول 3 أو أكثر
الخوارزمية:
dp[i][diff]: عدد التتابعات المنتهية عند i بالفرق diff
لكل زوج (j,i):
حساب الفرق
الحصول على عدد التتابعات المنتهية عند j بنفس الفرق
تحديث العدد عند i (إضافة 1 للزوج نفسه)
إضافة إلى النتيجة عدد التتابعات الممتدة إلى طول 3 أو أكثر
مثال: [2,4,6,8,10]:
[2,4]: diff=2، dp[1][2]=1
[2,6]: diff=4، dp[2][4]=1
[4,6]: diff=2، dp[2][2]=1
[2,4,6]: diff=2، dp[2][2]=2، result+=1
استمر لجميع الأزواج...
النتيجة النهائية: 7
التعقيد:
الزمن: O(n²) - فحص كل الأزواج
المساحة: O(n²) - تخزين الفروق عند كل موضع
The solution handles all constraints:

Works for array length 1 to 1000
Handles integer range -2³¹ to 2³¹-1
Correctly counts all arithmetic subsequences
Returns result fitting in 32-bit integer