class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int result = nums.size();
            
            for (int i = 0; i < nums.size(); i++) {
                result ^= i ^ nums[i];
            }
            
            return result;
        }
    };
    XOR Approach Explanation:
    
    XOR of a number with itself is 0
    XOR of a number with 0 is the number itself
    By XORing all indices [0,n] with all array elements, all paired numbers cancel out, leaving the missing number
    Time Complexity: O(n) for both solutions
    
    Sum approach: One pass through the array
    XOR approach: One pass through the array
    Space Complexity: O(1) for both solutions
    
    No extra space needed beyond a few variables
    Example:
    For nums = [3,0,1]:
    
    Sum approach:
    n = 3
    Expected sum = 3 * 4 / 2 = 6
    Actual sum = 3 + 0 + 1 = 4
    Missing = 6 - 4 = 2
    XOR approach:
    result = 3
    3 ^ (0 ^ 3) ^ (1 ^ 0) ^ (2 ^ 1)
    = 3 ^ 3 ^ 0 ^ 0 ^ 2 ^ 1 ^ 1
    = 0 ^ 0 ^ 0 ^ 2
    = 2
    Both solutions handle all constraints:
    
    Works for n = nums.length
    1 ≤ n ≤ 10⁴
    0 ≤ nums[i] ≤ n
    Unique numbers in nums
    The sum approach might be more intuitive, while the XOR approach can be slightly more efficient as it avoids potential overflow issues in some cases. Both will correctly return 2 for [3,0,1], 2 for [0,1], and 8 for [9,6,4,2,3,5,7,0,1].