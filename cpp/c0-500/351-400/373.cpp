#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Result vector to store the k smallest pairs
        vector<vector<int>> result;
        
        // Edge cases
        if (nums1.empty() || nums2.empty() || k <= 0) {
            return result;
        }
        
        // Min heap to store pairs along with their indices
        // Format: {sum, index_in_nums1, index_in_nums2}
        auto cmp = [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<0>(a) > get<0>(b); // Min heap based on sum
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> pq(cmp);
        
        // Push initial pairs with first element of nums1 and all elements of nums2
        for (int j = 0; j < nums2.size() && j < k; j++) {
            pq.push({nums1[0] + nums2[j], 0, j});
        }
        
        // Extract k smallest pairs
        while (k > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            
            // Add the pair to result
            result.push_back({nums1[i], nums2[j]});
            k--;
            
            // If we can move to next element in nums1
            if (i + 1 < nums1.size()) {
                pq.push({nums1[i + 1] + nums2[j], i + 1, j});
            }
        }
        
        return result;
    }
};
This solution uses a min-heap approach with the following logic:

Data Structure: We use a min-heap (priority_queue with custom comparator) that stores tuples containing:
Sum of the pair
Index in nums1
Index in nums2
Algorithm:
First, handle edge cases (empty arrays or k <= 0)
Initially push all pairs with the first element of nums1 and each element of nums2 into the heap
For k times (or until heap is empty):
Extract the minimum sum pair from heap
Add it to result
Push the next possible pair using the next element from nums1 with same nums2 element
Time Complexity: O(k * log m), where m is min(nums2.length, k)
Initial heap construction: O(m)
k extractions and insertions: O(k * log m)
Space Complexity: O(m) for the heap, where m is min(nums2.length, k)
Key Points:
We don't need to generate all possible pairs (which would be O(n*m))
We only explore the next possible minimum by moving forward in nums1
The arrays being sorted helps us maintain the minimum sum property
We stop after finding k pairs
Example walkthrough for nums1 = [1,7,11], nums2 = [2,4,6], k = 3:

Initial heap: [(3,0,0), (5,0,1), (7,0,2)] // sums with 1
Pop (3,0,0) → output [1,2], push (9,1,0) // sum with 7
Pop (5,0,1) → output [1,4], push (11,1,1)
Pop (7,0,2) → output [1,6], push (13,1,2) Result: [[1,2], [1,4], [1,6]]
The solution optimizes by:

Only keeping track of potentially minimum sums
Avoiding generation of all possible pairs
Using the sorted property to explore pairs in order
Maintaining heap size bounded by min(nums2.length, k)