Steps:
Count Frequencies:

Use a hash map (unordered_map) to count the frequency of each element in the first array (nums1).

Find Intersection:

Iterate through the second array (nums2):

If an element exists in the hash map and its count is greater than 0, add it to the result and decrement its count in the hash map.

Return the Result:

Return the result as a vector.

C++ Implementation:
cpp
Copy
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Count frequencies of elements in nums1
        unordered_map<int, int> frequencyMap;
        for (int num : nums1) {
            frequencyMap[num]++;
        }

        // Step 2: Find intersection with nums2
        vector<int> result;
        for (int num : nums2) {
            if (frequencyMap.find(num) != frequencyMap.end() && frequencyMap[num] > 0) {
                result.push_back(num); // Add to result
                frequencyMap[num]--;   // Decrement frequency
            }
        }

        // Step 3: Return the result
        return result;
    }
};
Explanation:
Count Frequencies:

We use a hash map (frequencyMap) to count how many times each element appears in nums1.

Find Intersection:

For each element in nums2, we check if it exists in the hash map and if its count is greater than 0.

If both conditions are met, we add the element to the result and decrement its count in the hash map.

Return the Result:

The result vector contains the intersection of the two arrays, with elements appearing as many times as they do in both arrays.

Example Walkthrough:
Input:
cpp
Copy
nums1 = [1, 2, 2, 1], nums2 = [2, 2]
Steps:
Count Frequencies:

frequencyMap = {1: 2, 2: 2}

Find Intersection:

For num = 2 in nums2:

2 is found in frequencyMap with count 2.

Add 2 to the result and decrement its count.

Result: [2]

frequencyMap = {1: 2, 2: 1}

For num = 2 in nums2:

2 is found in frequencyMap with count 1.

Add 2 to the result and decrement its count.

Result: [2, 2]

frequencyMap = {1: 2, 2: 0}

Return the Result:

Final result: [2, 2]

Output:
cpp
Copy
[2, 2]
Complexity Analysis:
Time Complexity:

Counting frequencies in nums1: 
O
(
n
)
O(n), where 
n
n is the size of nums1.

Iterating through nums2 and checking for intersection: 
O
(
m
)
O(m), where 
m
m is the size of nums2.

Overall: 
O
(
n
+
m
)
O(n+m).

Space Complexity:

Hash map: 
O
(
n
)
O(n) in the worst case (all elements in nums1 are unique).

Result vector: 
O
(
k
)
O(k), where 
k
k is the size of the intersection.

Overall: 
O
(
n
+
k
)
O(n+k).