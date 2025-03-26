Steps:
Count Frequencies:

Use a hash map (unordered_map) to count the frequency of each element in the array.

Use a Min-Heap:

Use a min-heap (priority queue) to keep track of the top k frequent elements.

The heap will store pairs of (frequency, element).

Since it's a min-heap, the element with the smallest frequency will be at the top. This allows us to efficiently replace it if we find a more frequent element.

Build the Result:

After processing all elements, extract the elements from the heap to form the result.

C++ Implementation:
cpp
Copy
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies using a hash map
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Step 2: Use a min-heap to find the top k frequent elements
        // The heap will store pairs of (frequency, element)
        // We use a custom comparator to make it a min-heap based on frequency
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first; // Min-heap based on frequency
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        for (const auto& entry : frequencyMap) {
            int num = entry.first;
            int freq = entry.second;

            minHeap.push({freq, num}); // Push (frequency, element) into the heap

            // If the heap size exceeds k, remove the element with the smallest frequency
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Step 3: Extract the top k elements from the heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second); // Add the element to the result
            minHeap.pop();
        }

        return result;
    }
};
Explanation:
Frequency Counting:

We iterate through the array and count the frequency of each element using a hash map (frequencyMap).

Min-Heap Usage:

We use a min-heap to keep track of the top k frequent elements.

For each element in the frequency map, we push a pair (frequency, element) into the heap.

If the heap size exceeds k, we remove the element with the smallest frequency (top of the min-heap).

Result Construction:

After processing all elements, the heap contains the top k frequent elements.

We extract these elements from the heap and add them to the result vector.

Example Walkthrough:
Input:
cpp
Copy
nums = [1, 1, 1, 2, 2, 3], k = 2
Steps:
Frequency Map:

Copy
{1: 3, 2: 2, 3: 1}
Min-Heap Operations:

Push (3, 1) → Heap: [(3, 1)]

Push (2, 2) → Heap: [(2, 2), (3, 1)]

Push (1, 3) → Heap size exceeds k, so pop (1, 3) → Heap: [(2, 2), (3, 1)]

Result:

Extract elements from the heap: [1, 2]

Output:
cpp
Copy
[1, 2]
Complexity Analysis:
Time Complexity:

Counting frequencies: 
O
(
n
)
O(n), where 
n
n is the size of the array.

Building the heap: 
O
(
m
log
⁡
k
)
O(mlogk), where 
m
m is the number of unique elements and 
k
k is the number of top elements.

Extracting elements from the heap: 
O
(
k
log
⁡
k
)
O(klogk).

Overall: 
O
(
n
+
m
log
⁡
k
)
O(n+mlogk).

Space Complexity:

Hash map: 
O
(
m
)
O(m).

Min-heap: 
O
(
k
)
O(k).

Overall: 
O
(
m
+
k
)
O(m+k).

This solution is efficient and works well within the given constraints.