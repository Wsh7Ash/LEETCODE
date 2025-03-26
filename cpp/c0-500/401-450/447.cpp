#include <vector>
#include <unordered_map>

class Solution {
private:
    // English: Calculate squared distance between two points
    // عربي: حساب المسافة المربعة بين نقطتين
    int getDistance(vector<int>& p1, vector<int>& p2) {
        int dx = p1[0] - p2[0];
        int dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }
    
public:
    // English: Find number of boomerangs in the points array
    // عربي: إيجاد عدد البوميرانغ في مصفوفة النقاط
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;
        
        // English: For each point as the first point (i)
        // عربي: لكل نقطة كالنقطة الأولى (i)
        for (int i = 0; i < points.size(); i++) {
            // English: Map to store distance -> count of points
            // عربي: جدول لتخزين المسافة -> عدد النقاط
            unordered_map<int, int> distanceCount;
            
            // English: Calculate distance to all other points
            // عربي: حساب المسافة إلى جميع النقاط الأخرى
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                int dist = getDistance(points[i], points[j]);
                distanceCount[dist]++;
            }
            
            // English: For each distance count, calculate number of boomerangs
            // English: For n points at same distance, number of pairs is n*(n-1)
            // عربي: لكل عدد مسافات، حساب عدد البوميرانغ
            // عربي: لـ n نقاط على نفس المسافة، عدد الأزواج هو n*(n-1)
            for (auto& pair : distanceCount) {
                int count = pair.second;
                if (count >= 2) {
                    result += count * (count - 1);
                }
            }
        }
        
        return result;
    }
};
English Explanation:
Approach:
For each point as pivot (i), count points at each distance
Use a hash map to store distance frequencies
For each distance with n points, calculate pairs: n*(n-1)
Algorithm:
For each point i:
Calculate distance to all other points
Store counts in map
For each distance count ≥ 2:
Add n*(n-1) to result (number of ways to pick 2 points)
Return total count
Example: [[0,0],[1,0],[2,0]]:
i=[0,0]: distances {1:1, 4:1} → 0 boomerangs
i=[1,0]: distances {1:2} → 2*1 = 2 boomerangs
i=[2,0]: distances {1:1, 4:1} → 0 boomerangs
Total: 2
Complexity:
Time: O(n²) - for each point, check all others
Space: O(n) - hash map size
شرح بالعربية:
النهج:
لكل نقطة كنقطة محور (i)، عد النقاط عند كل مسافة
استخدام جدول تجزئة لتخزين تكرارات المسافات
لكل مسافة بها n نقاط، حساب الأزواج: n*(n-1)
الخوارزمية:
لكل نقطة i:
حساب المسافة إلى كل النقاط الأخرى
تخزين العدد في الجدول
لكل عدد مسافات ≥ 2:
إضافة n*(n-1) إلى النتيجة (عدد طرق اختيار نقطتين)
إرجاع العدد الإجمالي
مثال: [[0,0],[1,0],[2,0]]:
i=[0,0]: مسافات {1:1, 4:1} → 0 بوميرانغ
i=[1,0]: مسافات {1:2} → 2*1 = 2 بوميرانغ
i=[2,0]: مسافات {1:1, 4:1} → 0 بوميرانغ
المجموع: 2
التعقيد:
الزمن: O(n²) - لكل نقطة، فحص كل الآخرين
المساحة: O(n) - حجم جدول التجزئة
Key Points:

Uses squared distance to avoid floating-point issues
Handles all constraints (n ≤ 500, coordinates in range)
Correctly counts ordered tuples where dist(i,j) = dist(i,k)
Works with single point case (returns 0)