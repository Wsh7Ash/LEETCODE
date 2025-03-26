#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // Create a vector of pairs with start time and original index
        // إنشاء متجه من الأزواج يحتوي على وقت البداية والفهرس الأصلي
        vector<pair<int, int>> starts;
        for (int i = 0; i < intervals.size(); i++) {
            starts.push_back({intervals[i][0], i});
        }
        
        // Sort by start time
        // ترتيب حسب وقت البداية
        sort(starts.begin(), starts.end());
        
        // Result vector
        // متجه النتائج
        vector<int> result(intervals.size(), -1);
        
        // For each interval's end time, find the smallest start time >= end time
        // لكل وقت نهاية فاصل، ابحث عن أصغر وقت بداية >= وقت النهاية
        for (int i = 0; i < intervals.size(); i++) {
            int end = intervals[i][1];
            
            // Binary search to find the first start >= end
            // البحث الثنائي لإيجاد أول بداية >= النهاية
            int left = 0, right = starts.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (starts[mid].first >= end) {
                    result[i] = starts[mid].second;
                    right = mid - 1;  // Try to find smaller start
                    // حاول إيجاد بداية أصغر
                } else {
                    left = mid + 1;
                }
            }
        }
        
        return result;
    }
};
Explanation in English:
Approach:
We use binary search to efficiently find the right interval for each interval.
First, we create a sorted array of start times with their original indices.
Then, for each interval's end time, we find the smallest start time that's greater than or equal to it.
Steps:
Create a vector of pairs (start time, index)
Sort by start time
For each interval:
Use binary search to find the first start time >= end time
Store the corresponding index in result array
Return result
Time Complexity: O(n log n) - sorting takes O(n log n) and binary search for each interval takes O(log n)
Space Complexity: O(n) for the starts vector and result vector
شرح بالعربية:
النهج:
نستخدم البحث الثنائي لإيجاد الفاصل الصحيح بكفاءة لكل فاصل.
أولاً، ننشئ مصفوفة مرتبة من أوقات البداية مع فهارسها الأصلية.
ثم، لكل وقت نهاية فاصل، نجد أصغر وقت بداية أكبر منه أو يساويه.
الخطوات:
إنشاء متجه من الأزواج (وقت البداية، الفهرس)
ترتيب حسب وقت البداية
لكل فاصل:
استخدام البحث الثنائي لإيجاد أول وقت بداية >= وقت النهاية
تخزين الفهرس المقابل في مصفوفة النتائج
إرجاع النتيجة
تعقيد الزمن: O(n log n) - الترتيب يأخذ O(n log n) والبحث الثنائي لكل فاصل يأخذ O(log n)
تعقيد المساحة: O(n) لمتجه البدايات ومتجه النتائج
Example Walkthrough (Example 2):
Input: [[3,4],[2,3],[1,2]]

Sorted starts: [(1,2), (2,1), (3,0)]
For [3,4]: end=4, no start ≥ 4 → -1
For [2,3]: end=3, first start ≥ 3 is 3 (index 0) → 0
For [1,2]: end=2, first start ≥ 2 is 2 (index 1) → 1 Output: [-1,0,1]
The solution handles all constraints and correctly finds the minimum right interval for each interval, returning -1 when no such interval exists.