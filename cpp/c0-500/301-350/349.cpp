Steps:
Store Unique Elements:

Use a hash set (unordered_set) to store all unique elements from the first array (nums1).

Find Intersection:

Iterate through the second array (nums2) and check if each element exists in the hash set.

If it exists, add it to the result and remove it from the hash set to ensure uniqueness.

Return the Result:

Return the result as a vector.

C++ Implementation:
cpp
Copy
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Store unique elements of nums1 in a hash set
        unordered_set<int> uniqueElements(nums1.begin(), nums1.end());

        // Step 2: Find intersection with nums2
        vector<int> result;
        for (int num : nums2) {
            if (uniqueElements.find(num) != uniqueElements.end()) {
                result.push_back(num); // Add to result
                uniqueElements.erase(num); // Ensure uniqueness
            }
        }

        // Step 3: Return the result
        return result;
    }
};
Explanation:
Store Unique Elements:

We initialize a hash set (uniqueElements) with the elements of nums1. This automatically removes duplicates.

Find Intersection:

We iterate through nums2 and check if each element exists in the hash set.

If it exists, we add it to the result and remove it from the hash set to avoid adding duplicates.

Return the Result:

The result vector contains the intersection of the two arrays with unique elements.

Example Walkthrough:
Input:
cpp
Copy
nums1 = [1, 2, 2, 1], nums2 = [2, 2]
Steps:
Store Unique Elements:

uniqueElements = {1, 2}

Find Intersection:

For num = 2 in nums2:

2 is found in uniqueElements, so add it to the result and remove it from the set.

Result: [2]

uniqueElements = {1}

Return the Result:

Final result: [2]

Output:
cpp
Copy
[2]
Complexity Analysis:
Time Complexity:

Storing elements of nums1 in the hash set: 
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

Hash set: 
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

