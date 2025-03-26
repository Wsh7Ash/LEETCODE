Problem Explanation:
We are given two integers, n and k. We need to find the k-th smallest integer in the range [1, n] when the numbers are sorted in lexicographical (dictionary) order. For example, the lexicographical order of numbers from 1 to 13 is:

Copy
[1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]
Here, the 2nd smallest number is 10.

Approach:
Lexicographical Order: Numbers are ordered as if they were strings. For example, 10 comes before 2 because '10' is lexicographically smaller than '2'.

Trie-like Traversal: We can think of the numbers as a trie (prefix tree) where each node represents a digit. We traverse this trie in lexicographical order to find the k-th smallest number.

Counting Nodes: For a given prefix, we calculate how many numbers fall under it in the range [1, n]. This helps us determine whether the k-th number lies under the current prefix or not.

Depth-First Search (DFS): We use a DFS-like approach to traverse the trie, moving to the next prefix if the current prefix does not contain the k-th number.

C++ Code with English and Arabic Comments:
cpp
Copy
class Solution {
public:
    int findKthNumber(int n, int k) {
        int result = 1; // Start with the smallest number
        // البدء بأصغر عدد
        k--; // Decrement k because we start counting from 1
        // إنقاص k لأننا نبدأ العد من 1
        
        while (k > 0) {
            // Calculate the number of nodes under the current prefix
            // حساب عدد العقد تحت البادئة الحالية
            long count = 0;
            long left = result;
            long right = result + 1;
            
            while (left <= n) {
                count += min((long)n + 1, right) - left;
                left *= 10;
                right *= 10;
            }
            
            if (count <= k) {
                // If the count is less than or equal to k, move to the next prefix
                // إذا كان العدد أقل من أو يساوي k، انتقل إلى البادئة التالية
                result++;
                k -= count;
            } else {
                // Otherwise, move deeper into the current prefix
                // وإلا، انتقل أعمق في البادئة الحالية
                result *= 10;
                k--;
            }
        }
        
        return result;
    }
};
Explanation:
Initialization: Start with the smallest number (1) and decrement k by 1 because we are counting from 1.

Counting Nodes:

For the current prefix (result), calculate how many numbers fall under it in the range [1, n].

Use left and right to represent the range of numbers under the current prefix.

For example, for result = 1, the range is [1, 2), then [10, 20), then [100, 200), etc.

Decision Making:

If the count of numbers under the current prefix is less than or equal to k, move to the next prefix (result++) and subtract the count from k.

Otherwise, move deeper into the current prefix (result *= 10) and decrement k by 1.

Repeat: Continue the process until k becomes 0.

Complexity:
Time Complexity: O(log n), as we are traversing the trie in a DFS-like manner, and the depth of the trie is logarithmic in n.

Space Complexity: O(1), as we are using a constant amount of extra space.

This approach efficiently finds the k-th smallest number in lexicographical order by simulating a trie traversal and counting the number of nodes under each prefix.