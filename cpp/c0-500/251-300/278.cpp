// The API is defined in the parent class
// bool isBadVersion(int version);

class Solution {
    public:
        int firstBadVersion(int n) {
            int left = 1;
            int right = n;
            
            while (left < right) {  // Note: < not <=
                int mid = left + (right - left) / 2;  // Avoid overflow
                
                if (isBadVersion(mid)) {
                    right = mid;  // Bad version found, look left for first
                } else {
                    left = mid + 1;  // Good version, look right
                }
            }
            
            return left;  // left == right at the first bad version
        }
    };
    How it works:
    
    Binary Search Approach:
    Treat versions as a sorted array where good versions (false) come before bad versions (true)
    We want the leftmost position where isBadVersion returns true
    Key Details:
    Use left + (right - left) / 2 instead of (left + right) / 2 to avoid integer overflow
    Loop condition is left < right (not ≤) because:
    When left == right, we've found the answer
    We want to stop before overshooting
    If mid is bad: first bad version is at mid or before
    If mid is good: first bad version is after mid
    Why it works:
    When loop ends, left == right points to the first bad version
    Each iteration halves the search space
    Time Complexity: O(log n) - Binary search
    Space Complexity: O(1) - Constant extra space
    
    Examples:
    
    n = 5, bad = 4:
    left=1, right=5, mid=3: isBadVersion(3)=false → left=4
    left=4, right=5, mid=4: isBadVersion(4)=true → right=4
    left=4, right=4: return 4
    n = 1, bad = 1:
    left=1, right=1: loop doesn't run, return 1
    Edge Cases Handled:
    
    n = 1 (single version)
    n = 2³¹ - 1 (max value)
    First version is bad
    Last version is first bad
    The solution minimizes API calls by:
    
    Using binary search instead of linear search
    Never calling isBadVersion more than log₂(n) times
    Correctly converging on the first bad version
    Constraints are met:
    
    Works for 1 ≤ bad ≤ n ≤ 2³¹ - 1
    Returns correct first bad version with minimal API calls