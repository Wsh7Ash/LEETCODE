class Solution {
    public:
        int hIndex(vector<int>& citations) {
            int n = citations.size();
            int left = 0;
            int right = n - 1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int papers = n - mid;  // Number of papers with at least citations[mid] citations
                
                if (citations[mid] == papers) {
                    return papers;  // Found exact match
                }
                else if (citations[mid] < papers) {
                    left = mid + 1;  // Need more citations, look right
                }
                else {
                    right = mid - 1;  // Too many citations, look left
                }
            }
            
            // When binary search ends, right will be at the highest valid h-index position
            return n - (right + 1);
        }
    };
    How it works:
    
    Key Insight:
    Since array is sorted ascending, for any index i:
    n - i papers have at least citations[i] citations
    We want the maximum h where h ≤ citations[i] and h = n - i
    Binary Search:
    Search for the point where citations[mid] ≈ (n - mid)
    If citations[mid] < (n - mid): need more citations, go right
    If citations[mid] > (n - mid): too many citations, go left
    When search ends, right points to the last valid position
    Edge Cases:
    If exact match found, return it
    Otherwise, h is the number of papers after right (n - (right + 1))
    Time Complexity: O(log n) - Binary search
    Space Complexity: O(1) - Constant extra space
    
    Examples:
    
    citations = [0,1,3,5,6], n = 5:
    left=0, right=4, mid=2: citations[2]=3, papers=5-2=3 ✓ return 3
    Result: 3
    citations = [1,2,100], n = 3:
    left=0, right=2, mid=1: citations[1]=2, papers=3-1=2 ✓ return 2
    Result: 2
    Detailed walk-through for [0,1,3,5,6]:
    
    left=0, right=4, mid=2: citations[2]=3, papers=3 ✓ return 3
    (Could continue, but finds exact match first try)
    For [1,2,100]:
    
    left=0, right=2, mid=1: citations[1]=2, papers=2 ✓ return 2
    The solution leverages:
    
    Sorted array property
    Binary search for O(log n) time
    Handles all constraints:
    1 ≤ n ≤ 10⁵
    0 ≤ citations[i] ≤ 1000
    Ascending order
    The key difference from H-Index I is that we can use binary search here due to the sorted input, making it more efficient than the O(n) or O(n log n) solutions required for the unsorted case.