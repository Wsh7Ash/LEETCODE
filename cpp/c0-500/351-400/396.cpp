class Solution {
    public:
        int maxRotateFunction(vector<int>& nums) {
            int n = nums.size();
            long long sum = 0;      // Sum of all elements
            long long current = 0;  // F(0)
            
            // Calculate initial sum and F(0)
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                current += i * nums[i];
            }
            
            long long maxValue = current;
            
            // Calculate F(k) for each rotation
            for (int i = 1; i < n; i++) {
                // F(k) = F(k-1) + sum - n * nums[n-k]
                current = current + sum - n * nums[n - i];
                maxValue = max(maxValue, current);
            }
            
            return maxValue;
        }
    };
    How this solution works:
    
    Key Insight:
    There's a mathematical relationship between consecutive F(k) values
    F(k) = F(k-1) + sum - n * last_element_of_previous_rotation
    This avoids recalculating the entire sum for each rotation
    Derivation:
    text
    
    Collapse
    
    Wrap
    
    Copy
    F(0) = 0*a[0] + 1*a[1] + 2*a[2] + 3*a[3]
    F(1) = 0*a[3] + 1*a[0] + 2*a[1] + 3*a[2]
    F(1) = F(0) + (a[0] + a[1] + a[2] + a[3]) - 4*a[3]
    General formula: F(k) = F(k-1) + sum - n * nums[n-k]
    Implementation:
    Calculate sum and F(0) first
    Use formula to get subsequent values
    Track maximum value seen
    Example Walkthrough (nums = [4,3,2,6]):
    text
    
    Collapse
    
    Wrap
    
    Copy
    sum = 15
    F(0) = 25
    F(1) = 25 + 15 - 4*6 = 16
    F(2) = 16 + 15 - 4*2 = 23
    F(3) = 23 + 15 - 4*3 = 26
    max = 26
    Complexity:
    Time: O(n) - single pass through array
    Space: O(1) - constant extra space
    Key Features:
    Uses long long to avoid integer overflow
    Handles single element arrays
    Efficiently finds maximum without explicit rotations
    The solution satisfies all constraints:
    
    Works for n from 1 to 10^5
    Handles values from -100 to 100
    Returns 32-bit integer result
    Alternative Brute Force Approach (for understanding):
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        int maxRotateFunction(vector<int>& nums) {
            int n = nums.size();
            int maxValue = INT_MIN;
            
            for (int k = 0; k < n; k++) {
                int current = 0;
                for (int i = 0; i < n; i++) {
                    current += i * nums[(i + k) % n];
                }
                maxValue = max(maxValue, current);
            }
            
            return maxValue;
        }
    };
    Time: O(n²)
    Space: O(1)
    The optimized solution is much more efficient than the brute force approach, especially for large n. It takes advantage of the mathematical relationship between consecutive rotations rather than recalculating each sum from scratch. This makes it suitable for the given constraint of n up to 10^5.