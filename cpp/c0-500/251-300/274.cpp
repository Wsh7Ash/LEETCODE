class Solution {
    public:
        int hIndex(vector<int>& citations) {
            int n = citations.size();
            vector<int> count(1001, 0);  // Max citation is 1000
            
            // Count occurrences of each citation value
            for (int citation : citations) {
                count[min(citation, n)]++;  // Cap at n since h-index can't exceed n
            }
            
            int h = 0;
            int sum = 0;  // Running sum of papers from highest citation
            
            // Count backwards from highest possible citation
            for (int i = n; i >= 0; i--) {
                sum += count[i];
                if (sum >= i) {
                    h = i;
                    break;
                }
            }
            
            return h;
        }
    };
    Time Complexity:
    
    Sorting solution: O(n log n) due to sorting
    Counting solution: O(n) as we make one pass to count and one to find h
    Space Complexity:
    
    Sorting solution: O(1) extra space (in-place sorting)
    Counting solution: O(1) since count array size is fixed (1001)
    Examples:
    
    citations = [3,0,6,1,5]:
    Sorted: [6,5,3,1,0]
    i=0: 6 ≥ 1, h=1
    i=1: 5 ≥ 2, h=2
    i=2: 3 ≥ 3, h=3
    i=3: 1 < 4, break
    Return 3
    citations = [1,3,1]:
    Sorted: [3,1,1]
    i=0: 3 ≥ 1, h=1
    i=1: 1 < 2, break
    Return 1
    Both solutions handle all constraints:
    
    1 ≤ n ≤ 5000
    0 ≤ citations[i] ≤ 1000 The counting solution is more efficient for this specific problem given the bounded citation values, while the sorting solution is more general-purpose and easier to understand.