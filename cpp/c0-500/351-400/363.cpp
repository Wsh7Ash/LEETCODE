class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length;
        int n = matrix[0].length;
        
        // Create prefix sum array
        int[][] prefixSum = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] 
                    - prefixSum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        int maxSum = Integer.MIN_VALUE;
        
        // Try all possible pairs of rows
        for (int r1 = 0; r1 < m; r1++) {
            for (int r2 = r1; r2 < m; r2++) {
                // Use TreeSet to find maximum sum <= k
                TreeSet<Integer> set = new TreeSet<>();
                set.add(0);
                
                // For each column
                for (int c = 0; c < n; c++) {
                    // Calculate sum between rows r1 and r2 up to column c
                    int sum = prefixSum[r2 + 1][c + 1] - prefixSum[r1][c + 1];
                    
                    // Find the largest sum <= k using ceiling
                    Integer ceiling = set.ceiling(sum - k);
                    if (ceiling != null) {
                        maxSum = Math.max(maxSum, sum - ceiling);
                    }
                    
                    set.add(sum);
                }
            }
        }
        
        return maxSum;
    }
}
Let's break down how this solution works:

Key Insight:
Convert 2D problem to multiple 1D problems using prefix sums
For each pair of rows, find maximum subarray sum ≤ k
Use TreeSet to efficiently find closest sum
Approach:
Build prefix sum array for O(1) rectangle sum calculation
Fix two rows at a time
For each column, calculate sum between these rows
Use TreeSet to find maximum sum not exceeding k
Algorithm Details:
Prefix sum calculation: prefixSum[i][j] = sum of rectangle from (0,0) to (i-1,j-1)
For rows r1 to r2 and column c: sum = prefixSum[r2+1][c+1] - prefixSum[r1][c+1]
TreeSet maintains cumulative sums and helps find closest value ≤ k
Example Walkthrough:
text
Wrap
Copy
matrix = [[1,0,1],[0,-2,3]], k = 2

Prefix sum:
[[0,0,0,0],
 [0,1,1,2],
 [0,1,-1,4]]

r1=0, r2=0: [1,0,1]
set: [0], [0,1], [0,1,1], [0,1,1,2]
maxSum = 1

r1=0, r2=1: [1,0,1,0,-2,3]
set: [0], [0,1], [0,1,1], [0,1,2], ...
maxSum = 2 (from [0,1,-2,3])

r1=1, r2=1: [0,-2,3]
maxSum = 2 (unchanged)
Time Complexity:
Prefix sum: O(mn)
Main algorithm: O(m²n log n) due to TreeSet operations
Total: O(m²n log n)
Space Complexity:
O(mn) for prefix sum array
O(n) for TreeSet
Why It Works:
Prefix sums allow quick rectangle sum calculation
TreeSet efficiently finds largest possible sum ≤ k
Considers all possible rectangles
Returns maximum sum not exceeding k
The solution handles all constraints:

Works for 1 ≤ m,n ≤ 100
Handles matrix values -100 to 100
Works for k from -10^5 to 10^5
Guaranteed to find a valid solution
This is an optimal solution for this problem, balancing time complexity with the need to check all possible rectangles while maintaining the k constraint.