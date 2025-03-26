#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        
        // Base case
        ans[0] = 0;
        
        // For each number from 1 to n
        for (int i = 1; i <= n; i++) {
            // Number of 1's in i = Number of 1's in (i/2) + LSB
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};

// Test code
#include <iostream>
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> result1 = solution.countBits(2);
    printVector(result1);  // 0 1 1
    
    // Test case 2
    vector<int> result2 = solution.countBits(5);
    printVector(result2);  // 0 1 1 2 1 2
    
    return 0;
}
How it works:

DP Approach:
Uses the fact that binary representation of a number can be derived from its half value
For any number i:
Right shift by 1 (i >> 1) gives us i/2
AND with 1 (i & 1) gives us the least significant bit
Key Insight:
Number of 1's in i = Number of 1's in (i/2) + whether i has a 1 in LSB
Examples:
2 (10) = 1 (1) + 0 = 1
3 (11) = 1 (1) + 1 = 2
4 (100) = 2 (10) + 0 = 1
5 (101) = 2 (10) + 1 = 2
Algorithm:
Initialize result array of size n+1
Set ans[0] = 0
For each i from 1 to n:
ans[i] = ans[i >> 1] + (i & 1)
Return the array
Example Walkthrough for n=5:
ans[0] = 0
ans[1] = ans[0] + 1 = 0 + 1 = 1
ans[2] = ans[1] + 0 = 1 + 0 = 1
ans[3] = ans[1] + 1 = 1 + 1 = 2
ans[4] = ans[2] + 0 = 1 + 0 = 1
ans[5] = ans[2] + 1 = 1 + 1 = 2
Complexity:

Time Complexity: O(n) - single pass from 0 to n
Space Complexity: O(n) - for the output array
The solution satisfies all constraints:

Works for n from 0 to 10^5
Returns correct bit counts for all numbers up to n
For the examples:

n=2 → [0,1,1]
0: 0
1: 1
2: 10
n=5 → [0,1,1,2,1,2]
0: 0
1: 1
2: 10
3: 11
4: 100
5: 101
This solution is efficient because:

Uses bit operations for fast computation
Builds solution incrementally
Avoids counting bits individually
Takes advantage of binary number patterns